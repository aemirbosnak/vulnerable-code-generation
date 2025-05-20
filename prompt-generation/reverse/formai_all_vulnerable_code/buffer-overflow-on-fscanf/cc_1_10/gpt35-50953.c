//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

//function to read file and store names in an array
int read_file(char* filename, char names[MAX][MAX], int* count) {
    FILE* file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        printf("ERROR: File not found\n");
        return -1;
    }
    int i = 0;
    while (fscanf(file_ptr, "%s", names[i]) != EOF) {
        i++;
    }
    *count = i;
    fclose(file_ptr);
    return 0;
}

//function to write names from an array to a file
int write_file(char* filename, char names[MAX][MAX], int count) {
    FILE* file_ptr = fopen(filename, "w");
    if (file_ptr == NULL) {
        printf("ERROR: Unable to open file\n");
        return -1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file_ptr, "%s\n", names[i]);
    }
    fclose(file_ptr);
    printf("Names written to %s successfully!\n", filename);
    return 0;
}

int main() {
    char filename[MAX];
    char names[MAX][MAX];
    int count = 0;

    printf("Enter name of file to read: ");
    scanf("%s", filename);

    int read = read_file(filename, names, &count);
    if (read == -1) {
        return -1;
    }

    printf("Names in the file:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    char new_name[MAX];
    printf("Enter a new name to add to the list: ");
    scanf("%s", new_name);

    //add new name to the array
    int index = count;
    for (int i = 0; i < count; i++) {
        if (strcmp(new_name, names[i]) <= 0) {
            index = i;
            break;
        }
    }

    for (int i = count; i > index; i--) {
        strcpy(names[i], names[i - 1]);
    }
    strcpy(names[index], new_name);
    count++;

    printf("New names in the file:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    printf("Enter name of file to write to: ");
    scanf("%s", filename);

    int write = write_file(filename, names, count);
    if (write == -1) {
        return -1;
    }

    return 0;
}