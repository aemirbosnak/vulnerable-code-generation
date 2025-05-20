//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#define BUFFSIZE 1024 * 1024
#define ITERATIONS 10

double calculate_speed(double bytes, double seconds) {
  return (bytes / 1024 / 1024) / seconds;
}

int main() {
  char *url = "https://speed.hetzner.de/100MB.bin";
  FILE *fp = fopen(url, "rb");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  printf("Your love for me is like a song,\nA melody that flows so strong.");
  printf("I will measure its speed, my dear,\nTo show you how much I hold you near.\n\n");

  double total_bytes = 0;
  double total_time = 0;
  for (int i = 0; i < ITERATIONS; i++) {
    char buffer[BUFFSIZE];
    struct timeval start, end;

    gettimeofday(&start, NULL);
    while (fread(buffer, 1, BUFFSIZE, fp) > 0) {
      total_bytes += BUFFSIZE;
    }
    gettimeofday(&end, NULL);

    total_time += (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    rewind(fp);
  }

  fclose(fp);

  double speed = calculate_speed(total_bytes, total_time);
  printf("The speed I found, my love, so true,\nIs like the stars that shine for you.");
  printf("It measures your devotion's might,\nA radiant beacon in the darkest night.\n\n");
  printf("Your love's speed is %.2f Mbps,\nA testament to our bond, perhaps?");

  return EXIT_SUCCESS;
}