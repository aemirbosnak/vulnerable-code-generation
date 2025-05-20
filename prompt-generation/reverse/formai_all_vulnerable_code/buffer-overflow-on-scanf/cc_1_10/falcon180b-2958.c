//Falcon-180B DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file and store its content in a string
void read_file(char *filename, char *buffer) {
    FILE *fp;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    while ((read = getline(&buffer[len], &len, fp))!= -1) {
        if (read > 0) {
            buffer[len] = '\0';
        }
    }

    fclose(fp);
}

// Function to write a string to a file
void write_file(char *filename, char *buffer) {
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    fprintf(fp, "%s", buffer);

    fclose(fp);
}

// Function to count the number of lines in a string
int count_lines(char *buffer) {
    int count = 0;
    char *line = strtok(buffer, "\n");

    while (line!= NULL) {
        count++;
        line = strtok(NULL, "\n");
    }

    return count;
}

// Function to reverse the order of lines in a string
void reverse_lines(char *buffer) {
    char *line = strtok(buffer, "\n");
    char *reversed = NULL;

    while (line!= NULL) {
        reversed = strcat(reversed, line);
        reversed = strcat(reversed, "\n");
        line = strtok(NULL, "\n");
    }

    strcpy(buffer, reversed);
}

int main() {
    char filename[100];
    char buffer[10000];

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    read_file(filename, buffer);

    printf("Number of lines in the file: %d\n", count_lines(buffer));

    reverse_lines(buffer);

    printf("Reversed content of the file:\n%s", buffer);

    write_file("reversed.txt", buffer);

    printf("Reversed content written to file reversed.txt\n");

    return 0;
}