//FormAI DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

struct person {
    char name[50];
    int age;
    char occupation[50];
};

int main() {
    char filename[50], line[100];
    FILE *fp;

    // get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // create/open file in write mode
    fp = fopen(filename, "w");

    // check if file was successfully opened
    if (fp == NULL) {
        printf("Unable to create/open file.\n");
        exit(1);
    }

    struct person p;
    printf("Enter name, age, and occupation (separated by space): ");
    scanf("%s %d %s", p.name, &p.age, p.occupation);

    // write struct data to file
    fprintf(fp, "%s %d %s\n", p.name, p.age, p.occupation);

    // close file
    fclose(fp);

    // open file in read mode
    fp = fopen(filename, "r");

    // check if file was successfully opened
    if (fp == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }

    // read and print file contents
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    // close file
    fclose(fp);

    return 0;
}