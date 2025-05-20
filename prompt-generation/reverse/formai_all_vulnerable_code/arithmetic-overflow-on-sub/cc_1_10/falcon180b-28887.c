//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    int i, j, k;
    struct rlimit rlim;
    char *ptr;
    long int pagesize;
    struct timeval start, end;
    double elapsed;

    pagesize = sysconf(_SC_PAGESIZE);

    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = rlim.rlim_max;
    setrlimit(RLIMIT_DATA, &rlim);

    ptr = (char *) malloc(rlim.rlim_cur);
    if (ptr == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    for (i = 0; i < rlim.rlim_cur; i += pagesize) {
        memset(ptr + i, 0, pagesize);
    }

    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = rlim.rlim_max;
    setrlimit(RLIMIT_DATA, &rlim);

    for (k = 0; k < 10; k++) {
        gettimeofday(&start, NULL);
        for (i = 0; i < rlim.rlim_cur; i += pagesize) {
            for (j = 0; j < pagesize; j++) {
                ptr[i + j] = rand() % 256;
            }
        }
        gettimeofday(&end, NULL);
        elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        printf("Iteration %d took %.2f seconds.\n", k + 1, elapsed);
    }

    free(ptr);
    return 0;
}