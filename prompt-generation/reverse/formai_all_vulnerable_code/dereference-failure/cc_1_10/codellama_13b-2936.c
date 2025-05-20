//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: intelligent
// C Data Mining Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing data
typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
    char email[50];
    char address[100];
} Data;

// Function for reading data from file
void readData(char *filename, Data *data, int *n) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '#') continue;
        if (i >= *n) {
            printf("Error: Array size exceeded!\n");
            break;
        }
        char *token = strtok(line, ",");
        data[i].id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(data[i].name, token);
        token = strtok(NULL, ",");
        data[i].age = atoi(token);
        token = strtok(NULL, ",");
        data[i].gender = token[0];
        token = strtok(NULL, ",");
        strcpy(data[i].email, token);
        token = strtok(NULL, ",");
        strcpy(data[i].address, token);
        i++;
    }
    *n = i;
    fclose(fp);
}

// Function for writing data to file
void writeData(char *filename, Data *data, int n) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d, %s, %d, %c, %s, %s\n", data[i].id, data[i].name, data[i].age, data[i].gender, data[i].email, data[i].address);
    }
    fclose(fp);
}

// Main function
int main() {
    Data data[100];
    int n = 100;
    readData("data.txt", data, &n);
    for (int i = 0; i < n; i++) {
        printf("%d: %s %s %d %c %s %s\n", data[i].id, data[i].name, data[i].email, data[i].age, data[i].gender, data[i].address);
    }
    writeData("output.txt", data, n);
    return 0;
}