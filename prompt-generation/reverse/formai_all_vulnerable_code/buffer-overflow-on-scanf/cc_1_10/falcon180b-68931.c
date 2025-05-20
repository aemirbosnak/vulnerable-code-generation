//Falcon-180B DATASET v1.0 Category: Data mining ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000
#define MAX_ATTRIBUTE_SIZE 100
#define NO_OF_ATTRIBUTES 5

struct Data {
    char *attributes[MAX_ATTRIBUTE_SIZE];
    int class;
};

struct Data data[MAX_DATA_SIZE];
int no_of_data = 0;

void read_data(char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i = 0;
    char line[100];
    while (fgets(line, 100, fp)!= NULL) {
        char *token = strtok(line, ",");
        int j = 0;
        while (token!= NULL && j < MAX_ATTRIBUTE_SIZE) {
            data[i].attributes[j] = token;
            token = strtok(NULL, ",");
            j++;
        }
        data[i].class = atoi(token);
        i++;
    }

    fclose(fp);
}

void preprocess_data() {
    int i, j;
    for (i = 0; i < no_of_data; i++) {
        for (j = 0; j < NO_OF_ATTRIBUTES; j++) {
            if (data[i].attributes[j] == NULL || strlen(data[i].attributes[j]) == 0) {
                data[i].attributes[j] = "NA";
            }
        }
    }
}

void mine_data(int attribute_index, int class_index) {
    int i;
    for (i = 0; i < no_of_data; i++) {
        if (data[i].attributes[attribute_index] == "Yes" && data[i].class == class_index) {
            printf("%s ", data[i].attributes[0]);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    read_data(filename);

    preprocess_data();

    int attribute_index, class_index;
    printf("Enter the attribute index: ");
    scanf("%d", &attribute_index);

    printf("Enter the class index: ");
    scanf("%d", &class_index);

    mine_data(attribute_index, class_index);

    return 0;
}