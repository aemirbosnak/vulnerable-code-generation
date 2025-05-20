//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compare two strings */
int compare(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minlen = (len1 < len2)? len1 : len2;
    int i;
    for(i=0; i<minlen; i++) {
        if(str1[i]!= str2[i]) {
            return 0;
        }
    }
    return 1;
}

/* Function to read CSV file and print its contents */
void readCSV(FILE *fp) {
    char line[1000];
    char *token;
    int count = 0;
    while(fgets(line, sizeof(line), fp)) {
        count++;
        token = strtok(line, ",");
        while(token!= NULL) {
            printf("%d : %s\n", count, token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage:./program filename.csv delimiter\n");
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char delimiter = argv[2][0];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while((read = getline(&line, &len, fp))!= -1) {
        line[read-1] = '\0';
        char *token = strtok(line, delimiter);
        while(token!= NULL) {
            printf("%s\n", token);
            token = strtok(NULL, delimiter);
        }
        printf("\n");
    }
    free(line);
    fclose(fp);
    return 0;
}