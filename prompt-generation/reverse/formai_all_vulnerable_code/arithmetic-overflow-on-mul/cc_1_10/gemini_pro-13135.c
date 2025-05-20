//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: ultraprecise
#include <stdlib.h>
#include <stdio.h>
#include <sys/resource.h>
#include <alloca.h>

int main()
{
    // Allocate a large block of memory
    int *ptr = malloc(100 * 1024 * 1024);
    if (ptr == NULL)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the current RAM usage
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) != 0)
    {
        perror("getrusage");
        free(ptr);
        return EXIT_FAILURE;
    }

    // Display the RAM usage
    printf("Current RAM usage: %ld bytes\n", usage.ru_maxrss * 1024);

    // Allocate some more memory using alloca
    int *alloca_ptr = alloca(1024);
    if (alloca_ptr == NULL)
    {
        perror("alloca");
        free(ptr);
        return EXIT_FAILURE;
    }

    // Read the current RAM usage again
    if (getrusage(RUSAGE_SELF, &usage) != 0)
    {
        perror("getrusage");
        free(ptr);
        free(alloca_ptr);
        return EXIT_FAILURE;
    }

    // Display the RAM usage again
    printf("Current RAM usage: %ld bytes\n", usage.ru_maxrss * 1024);

    // Free the memory
    free(ptr);
    free(alloca_ptr);

    return EXIT_SUCCESS;
}