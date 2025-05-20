//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define BUF_SIZE 1024
#define NUM_ITERATIONS 100

void print_usage() {
  printf("Usage: %s <url>\n", "speed-test");
}

int main(int argc, char** argv) {
  if (argc != 2) {
    print_usage();
  }

  char* url = argv[1];

  struct timeval start, end;
  double elapsed_time;
  double average_download_speed;
  double average_upload_speed;

  for (int i = 0; i < NUM_ITERATIONS; i++) {
    // Download test
    gettimeofday(&start, NULL);
    FILE* fp = fopen(url, "r");
    if (fp == NULL) {
      perror("fopen");
      return -1;
    }
    char* buf = malloc(BUF_SIZE);
    while (fread(buf, 1, BUF_SIZE, fp) != 0);
    fclose(fp);
    free(buf);
    gettimeofday(&end, NULL);
    elapsed_time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000;
    average_download_speed += (double)BUF_SIZE / (elapsed_time * 1024 * 1024);

    // Upload test
    gettimeofday(&start, NULL);
    fp = fopen(url, "w");
    if (fp == NULL) {
      perror("fopen");
      return -1;
    }
    fwrite(buf, 1, BUF_SIZE, fp);
    fclose(fp);
    gettimeofday(&end, NULL);
    elapsed_time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000;
    average_upload_speed += (double)BUF_SIZE / (elapsed_time * 1024 * 1024);
  }

  average_download_speed /= NUM_ITERATIONS;
  average_upload_speed /= NUM_ITERATIONS;

  printf("Average download speed: %.2f MB/s\n", average_download_speed);
  printf("Average upload speed: %.2f MB/s\n", average_upload_speed);

  return 0;
}