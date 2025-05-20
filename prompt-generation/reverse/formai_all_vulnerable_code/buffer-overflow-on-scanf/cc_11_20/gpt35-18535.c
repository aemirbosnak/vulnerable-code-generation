//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for recovered data
struct virtual_data {
    char filename[100];
    char data[100];
};

int main() {
    // Initializing variables
    FILE *fp;
    char ch, search[100], filename[100], output[100];
    int count = 0, i = 0, j = 0, n = 0, k = 0;
    struct virtual_data v[100];

    // User input
    printf("Enter the name of the file to recover data from: ");
    scanf("%s", filename);

    // Opening file in read mode
    fp = fopen(filename, "r");

    // Checking if file exists
    if (fp == NULL) {
        printf("Error, cannot open file\n");
        exit(0);
    }

    // User input for data to search
    printf("Enter the data to recover: ");
    scanf("%s", search);

    // Reading file character by character
    while ((ch = fgetc(fp)) != EOF) {
        // Matching data to search
        if (ch == search[i]) {
            i++;
            // If data matches
            if (i == strlen(search)) {
                // Storing recovered data in struct
                strncpy(v[count].data, search, strlen(search));
                i = 0;
                n = 1;
            }
        } else {
            i = 0;
        }

        // Storing file name in struct
        if (ch == '/') {
            j = 1;
        }
        if (j == 1) {
            v[count].filename[k] = ch;
            k++;
        }
        if (ch == '\n') {
            j = 0;
            // Incrementing count if data is found in file
            if (n == 1) {
                count++;
                n = 0;
            }
        }
        k = 0;
    }

    // Closing file
    fclose(fp);

    // Displaying recovered data
    if (count == 0) {
        printf("No data found\n");
    } else {
        printf("Data recovered from %d files\n", count);
        for (int i = 0; i < count; i++) {
            strncpy(output, v[i].filename + 1, strlen(v[i].filename) - 2);
            printf("%s : %s\n", output, v[i].data);
        }
    }

    return 0;
}