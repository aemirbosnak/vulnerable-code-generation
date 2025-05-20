//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_DEPTH 5

void print_tree(const char *str, int depth);

int main() {
    int choice;
    char str[MAX_STR_LEN];

    printf("Welcome to the Recursive Tree Printer!\n");

    do {
        printf("1. Print a tree with a single root node\n");
        printf("2. Print a tree with multiple root nodes\n");
        printf("3. Print a tree with branches and leaves\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the root node: ");
                fgets(str, MAX_STR_LEN, stdin);
                print_tree(str, MAX_DEPTH);
                break;
            case 2:
                printf("Enter the first root node: ");
                fgets(str, MAX_STR_LEN, stdin);
                print_tree(str, MAX_DEPTH);
                printf("Enter the second root node: ");
                fgets(str, MAX_STR_LEN, stdin);
                print_tree(str, MAX_DEPTH);
                break;
            case 3:
                printf("Enter the root node: ");
                fgets(str, MAX_STR_LEN, stdin);
                print_tree(str, MAX_DEPTH);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}

void print_tree(const char *str, int depth) {
    int i, j;
    char c;

    if (depth == 0) {
        printf("%s\n", str);
        return;
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            printf("(");
            print_tree(str + i + 1, depth - 1);
            printf(") ");
            continue;
        }

        if (str[i] == ' ') {
            continue;
        }

        printf("%c", str[i]);
    }
}