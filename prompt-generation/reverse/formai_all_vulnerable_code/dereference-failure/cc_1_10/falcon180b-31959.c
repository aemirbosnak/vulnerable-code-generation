//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

int main() {

    char *arr[MAX_SIZE];
    int n = 0;

    while (1) {
        printf("Enter a string or type 'done' to finish: ");
        char input[100];
        fgets(input, 100, stdin);

        if (strcmp(input, "done") == 0) {
            break;
        }

        arr[n] = malloc(strlen(input) + 1);
        strcpy(arr[n], input);
        n++;
    }

    while (1) {
        printf("Enter a search string: ");
        char input[100];
        fgets(input, 100, stdin);

        int found = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(arr[i], input) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Found!\n");
        } else {
            printf("Not found.\n");
        }
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }

    return 0;
}