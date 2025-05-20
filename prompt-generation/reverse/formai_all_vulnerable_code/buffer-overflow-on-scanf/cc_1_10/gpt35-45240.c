//FormAI DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void writeToFile(FILE *file, int num) {
    int i, value;
    
    for (i = 0; i < num; i++) {
        printf("Enter the value of element %d: ", i+1);
        scanf("%d", &value);
        fprintf(file, "%d ", value);
    }
    
    printf("\nDone writing to file!\n");
}

void readFromFile(FILE *file, int num) {
    int i, value;
    
    for (i = 0; i < num; i++) {
        fscanf(file, "%d", &value);
        printf("Element %d: %d\n", i+1, value);
    }
    
    printf("\nDone reading from file!\n");
}

int main() {
    FILE *file;
    char filename[20];
    int num, option;
    
    printf("Enter filename with extension: ");
    scanf("%s", filename);
    
    file = fopen(filename, "w+");
    
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }
    
    printf("How many elements do you want to write to the file? ");
    scanf("%d", &num);
    
    writeToFile(file, num);
    
    fseek(file, 0, SEEK_SET);
    
    printf("\nDo you want to read from the file? (1 for YES, 0 for NO): ");
    scanf("%d", &option);
    
    if (option == 1) {
        readFromFile(file, num);
    }
    
    fclose(file);
    
    return 0;
}