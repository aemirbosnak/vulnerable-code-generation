//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#define BUFF_SIZE 1024 * 1024

int main() {
    char *url = "http://speedtest.net/speedtest-files/10MB.zip";
    char *buff = malloc(BUFF_SIZE);
    if (!buff) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    #ifdef _WIN32
    LARGE_INTEGER start, end, frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    #else
    struct timeval start, end;
    gettimeofday(&start, NULL);
    #endif

    FILE *f = fopen(url, "rb");
    if (!f) {
        perror("fopen");
        free(buff);
        return EXIT_FAILURE;
    }

    size_t total = 0;
    while (1) {
        size_t bytes = fread(buff, 1, BUFF_SIZE, f);
        if (bytes == 0) {
            break;
        }
        total += bytes;
    }
    fclose(f);

    #ifdef _WIN32
    QueryPerformanceCounter(&end);
    double elapsed = (double)(end.QuadPart - start.QuadPart) / (double)frequency.QuadPart;
    #else
    gettimeofday(&end, NULL);
    double elapsed = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;
    #endif

    double speed = total / elapsed;
    printf("Download speed: %.2f MB/s\n", speed / (1024 * 1024.0));

    free(buff);
    return EXIT_SUCCESS;
}