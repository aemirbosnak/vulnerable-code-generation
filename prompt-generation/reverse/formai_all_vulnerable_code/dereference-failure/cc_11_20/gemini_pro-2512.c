//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare the main function
int main(void) {

    // Declare the variables
    int i, j, k, l, m, n;
    char *str, *ptr;
    FILE *fp;
    time_t t;

    // Open the file
    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file into a string
    str = malloc(100000);
    if (str == NULL) {
        perror("Error allocating memory");
        return EXIT_FAILURE;
    }
    fread(str, 1, 100000, fp);
    fclose(fp);

    // Parse the string
    ptr = strtok(str, " ");    
    i = 0;
    while (1) {
        if ((ptr != NULL) && (ptr[0] == '\n')) {
            ptr = strtok(NULL, " ");
            i++;
            k = 0;
        }
        if (ptr == NULL) {
            break;
        }
        j = 0;
        while ((ptr != NULL) && (ptr[j] != '\t') && (ptr[j] != '\n')) {
            j++;
        }
        if (ptr[k] == '[') {
            k++;
        }
        m = k;
        while ((ptr != NULL) && (ptr[m] != ']') && (ptr[m] != '\n')) {
            m++;
        }
        if (ptr[m] == ']') {
            m++;
        }
        n = m;
        while ((ptr != NULL) && (ptr[n] != '\n')) {
            n++;
        }
        if (ptr[n] == '\n') {
            n++;
        }
        ptr[n] = '\0';
        ptr[m] = '\0';
        printf("%d.%d %s %s\n", i + 1, k - 1, ptr + k, ptr + m);
        ptr = strtok(NULL, " ");
    }

    // Free the memory
    free(str);

    // Return success
    return EXIT_SUCCESS;
}