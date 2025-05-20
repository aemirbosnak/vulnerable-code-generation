//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_FILES 100
#define MAX_THREADS 10
#define MAX_BUF_SIZE 1024

struct file_sync_info {
  char *file_name;
  int file_size;
  char *file_data;
};

struct file_sync_args {
  int num_files;
  struct file_sync_info *file_infos;
  pthread_barrier_t *barrier;
  sem_t *sem;
};

void *file_sync_thread(void *args) {
  struct file_sync_args *arg = (struct file_sync_args *)args;
  int i;
  for (i = 0; i < arg->num_files; i++) {
    // Read the file into memory.
    FILE *fp = fopen(arg->file_infos[i].file_name, "rb");
    if (fp == NULL) {
      perror("fopen");
      exit(1);
    }
    arg->file_infos[i].file_data = malloc(arg->file_infos[i].file_size);
    if (arg->file_infos[i].file_data == NULL) {
      perror("malloc");
      exit(1);
    }
    fread(arg->file_infos[i].file_data, arg->file_infos[i].file_size, 1, fp);
    fclose(fp);

    // Wait for all threads to finish reading.
    pthread_barrier_wait(arg->barrier);

    // Write the data to the synchronized file.
    fp = fopen("synchronized_file.txt", "ab");
    if (fp == NULL) {
      perror("fopen");
      exit(1);
    }
    fwrite(arg->file_infos[i].file_data, arg->file_infos[i].file_size, 1, fp);
    fclose(fp);

    // Free the memory.
    free(arg->file_infos[i].file_data);
  }

  // Signal that this thread is done.
  sem_post(arg->sem);
  return NULL;
}

int main() {
  int num_files, i;
  struct file_sync_info file_infos[MAX_FILES];
  pthread_t threads[MAX_THREADS];
  pthread_barrier_t barrier;
  sem_t sem;

  // Get the number of files to synchronize.
  printf("Enter the number of files to synchronize: ");
  scanf("%d", &num_files);

  // Get the file information.
  for (i = 0; i < num_files; i++) {
    printf("Enter the name of file %d: ", i + 1);
    scanf("%s", file_infos[i].file_name);

    printf("Enter the size of file %d: ", i + 1);
    scanf("%d", &file_infos[i].file_size);
  }

  // Initialize the synchronization primitives.
  pthread_barrier_init(&barrier, NULL, num_files);
  sem_init(&sem, 0, 0);

  // Create the threads.
  struct file_sync_args args = {num_files, file_infos, &barrier, &sem};
  for (i = 0; i < num_files; i++) {
    if (pthread_create(&threads[i], NULL, file_sync_thread, &args) != 0) {
      perror("pthread_create");
      exit(1);
    }
  }

  // Wait for all threads to finish.
  for (i = 0; i < num_files; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the synchronization primitives.
  pthread_barrier_destroy(&barrier);
  sem_destroy(&sem);

  return 0;
}