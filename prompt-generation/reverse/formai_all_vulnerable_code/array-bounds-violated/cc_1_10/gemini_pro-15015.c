//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Function to read a line from the input file
char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, fp);
    return line;
}

// Function to parse a line of text and extract the boot time
int parse_boot_time(char *line) {
    char *token = strtok(line, ":");
    if (token == NULL) {
        return -1;
    }

    token = strtok(NULL, ":");
    if (token == NULL) {
        return -1;
    }

    int boot_time = atoi(token);
    return boot_time;
}

// Function to sort the boot times in ascending order
int compare_boot_times(const void *a, const void *b) {
    int *boot_time1 = (int *)a;
    int *boot_time2 = (int *)b;
    return *boot_time1 - *boot_time2;
}

int main() {
    FILE *fp = fopen("boot_times.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    int boot_times[MAX_STR_LEN];
    int num_boot_times = 0;

    // Read the boot times from the input file
    while ((line = read_line(fp)) != NULL) {
        int boot_time = parse_boot_time(line);
        if (boot_time > 0) {
            boot_times[num_boot_times++] = boot_time;
        }
    }

    // Sort the boot times in ascending order
    qsort(boot_times, num_boot_times, sizeof(int), compare_boot_times);

    // Print the sorted boot times
    printf("Sorted boot times:\n");
    for (int i = 0; i < num_boot_times; i++) {
        printf("%d\n", boot_times[i]);
    }

    // Find the median boot time
    int median_boot_time;
    if (num_boot_times % 2 == 0) {
        median_boot_time = (boot_times[num_boot_times / 2] + boot_times[num_boot_times / 2 - 1]) / 2;
    } else {
        median_boot_time = boot_times[num_boot_times / 2];
    }

    // Print the median boot time
    printf("Median boot time: %d\n", median_boot_time);

    // Free the allocated memory
    free(line);
    fclose(fp);

    return EXIT_SUCCESS;
}