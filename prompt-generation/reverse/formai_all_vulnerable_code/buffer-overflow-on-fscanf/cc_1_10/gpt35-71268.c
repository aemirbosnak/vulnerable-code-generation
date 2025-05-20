//FormAI DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>

int main() {
    // Declare necessary variables
    int numFiles, i, j, k, numData;
    char fileName[100], fileType[10];
    FILE *file;

    // Get user input for number of files to be processed
    printf("Enter the number of files to be processed: ");
    scanf("%d", &numFiles);

    for (i = 0; i < numFiles; i++) {
        // Get user input for file name and type
        printf("Enter the file name: ");
        scanf("%s", fileName);
        printf("Enter the file type: ");
        scanf("%s", fileType);

        // Open file for reading
        file = fopen(fileName, "r");

        // Check if file was successfully opened
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        // Get user input for number of data to be recovered
        printf("Enter the number of data to be recovered: ");
        scanf("%d", &numData);

        // Declare and initialize array to store recovered data
        int data[numData];
        for (j = 0; j < numData; j++) {
            data[j] = 0;
        }

        // Read data from file
        k = 0;
        while (fscanf(file, "%d", &data[k]) == 1) {
            k++;
        }

        // Close file
        fclose(file);

        // Print recovered data
        printf("Recovered data from file %s.%s:\n", fileName, fileType);
        for (j = 0; j < k; j++) {
            printf("%d\n", data[j]);
        }
    }

    return 0;
}