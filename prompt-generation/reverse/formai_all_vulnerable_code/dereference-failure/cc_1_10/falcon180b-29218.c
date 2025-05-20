//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RATINGS 10
#define MAX_LINES 1000

struct rating {
    char name[50];
    int value;
    char comment[100];
};

int main() {
    FILE *fp;
    char line[100];
    char *token;
    int count = 0;
    struct rating ratings[MAX_RATINGS];

    fp = fopen("ratings.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count == MAX_RATINGS) {
            printf("Maximum number of ratings reached\n");
            break;
        }

        token = strtok(line, ",");
        strcpy(ratings[count].name, token);

        token = strtok(NULL, ",");
        ratings[count].value = atoi(token);

        token = strtok(NULL, ",");
        strcpy(ratings[count].comment, token);

        count++;
    }

    fclose(fp);

    printf("Movie Ratings:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", ratings[i].name);
        printf("Value: %d\n", ratings[i].value);
        printf("Comment: %s\n\n", ratings[i].comment);
    }

    return 0;
}