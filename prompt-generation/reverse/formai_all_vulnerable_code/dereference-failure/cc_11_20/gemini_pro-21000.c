//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 4096

typedef struct {
  char *name;
  struct stat st;
  unsigned char *data;
  size_t data_len;
} file_info;

static int
compare_files(const void *a, const void *b)
{
  const file_info *fa = (const file_info *)a;
  const file_info *fb = (const file_info *)b;

  return strcmp(fa->name, fb->name);
}

int
main(int argc, char *argv[])
{
  DIR *dirp;
  struct dirent *dp;
  struct stat st;
  int fd;
  unsigned char buf[BUF_SIZE];
  ssize_t nread;
  file_info *files;
  size_t files_len;
  size_t files_cap;
  char *backup_dir;
  char *backup_file;
  int i;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <source-directory> <backup-directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  backup_dir = argv[2];
  if (stat(backup_dir, &st) == -1) {
    if (mkdir(backup_dir, 0755) == -1) {
      perror("mkdir");
      return EXIT_FAILURE;
    }
  } else if (!S_ISDIR(st.st_mode)) {
    fprintf(stderr, "%s is not a directory\n", backup_dir);
    return EXIT_FAILURE;
  }

  files_len = 0;
  files_cap = 100;
  files = malloc(files_cap * sizeof(*files));
  if (files == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  dirp = opendir(argv[1]);
  if (dirp == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  while ((dp = readdir(dirp)) != NULL) {
    if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
      continue;

    snprintf(backup_file, sizeof(backup_file), "%s/%s", backup_dir, dp->d_name);

    if (files_len >= files_cap) {
      files_cap *= 2;
      files = realloc(files, files_cap * sizeof(*files));
      if (files == NULL) {
        perror("realloc");
        return EXIT_FAILURE;
      }
    }

    files[files_len].name = strdup(dp->d_name);
    if (files[files_len].name == NULL) {
      perror("strdup");
      return EXIT_FAILURE;
    }

    if (stat(dp->d_name, &files[files_len].st) == -1) {
      perror("stat");
      return EXIT_FAILURE;
    }

    fd = open(dp->d_name, O_RDONLY);
    if (fd == -1) {
      perror("open");
      return EXIT_FAILURE;
    }

    files[files_len].data_len = files[files_len].st.st_size;
    files[files_len].data = malloc(files[files_len].data_len);
    if (files[files_len].data == NULL) {
      perror("malloc");
      return EXIT_FAILURE;
    }

    while ((nread = read(fd, buf, BUF_SIZE)) > 0) {
      if (files[files_len].data_len + nread > files[files_len].st.st_size) {
        files[files_len].data = realloc(files[files_len].data,
                                      files[files_len].data_len + nread);
        if (files[files_len].data == NULL) {
          perror("realloc");
          return EXIT_FAILURE;
        }
      }
      memcpy(files[files_len].data + files[files_len].data_len, buf, nread);
      files[files_len].data_len += nread;
    }
    if (nread == -1) {
      perror("read");
      return EXIT_FAILURE;
    }

    if (close(fd) == -1) {
      perror("close");
      return EXIT_FAILURE;
    }

    files_len++;
  }

  if (closedir(dirp) == -1) {
    perror("closedir");
    return EXIT_FAILURE;
  }

  qsort(files, files_len, sizeof(*files), compare_files);

  for (i = 0; i < files_len; i++) {
    fd = open(backup_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
      perror("open");
      return EXIT_FAILURE;
    }

    if (write(fd, files[i].data, files[i].data_len) == -1) {
      perror("write");
      return EXIT_FAILURE;
    }

    if (close(fd) == -1) {
      perror("close");
      return EXIT_FAILURE;
    }

    free(files[i].data);
    free(files[i].name);
  }

  free(files);

  return EXIT_SUCCESS;
}