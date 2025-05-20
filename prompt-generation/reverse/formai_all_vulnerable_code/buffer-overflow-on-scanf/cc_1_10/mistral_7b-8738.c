//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char name[MAX];
    int age;
} Person;

void encrypt(char *str, int key) {
    int i;
    for (i = 0; str[i]; i++) {
        if (isalpha(str[i]))
            str[i] = (char)fabs((int)str[i] + key);
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}

void decrypt(char *str, int key) {
    int i;
    for (i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = (char)fabs((int)str[i] - key);
            str[i] -= 32;
        }
    }
}

int search(Person arr[], char *name, int n) {
    int i, flag = 1;
    encrypt(name, 7);
    for (i = 0; i < n; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            flag = 0;
            break;
        }
    }
    decrypt(name, 7);
    return flag;
}

int main() {
    Person arr[MAX];
    int i, n, flag;
    char searchName[MAX];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", arr[i].name);
        printf("Age %d: ", i + 1);
        scanf("%d", &arr[i].age);
    }

    printf("\nEnter the name to search: ");
    scanf("%s", searchName);

    flag = search(arr, searchName, n);

    if (flag)
        printf("Name not found.\n");
    else
        printf("Name found.\n");

    return 0;
}