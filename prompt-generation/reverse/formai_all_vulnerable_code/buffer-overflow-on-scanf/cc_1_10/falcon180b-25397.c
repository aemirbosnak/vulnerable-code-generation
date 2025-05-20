//Falcon-180B DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[50];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+{}|:<>?-=[]\\;',./";
    int i;
    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[length] = '\0';
}

int compare_passwords(const void* a, const void* b) {
    const password_t* p1 = (const password_t*)a;
    const password_t* p2 = (const password_t*)b;
    return strcmp(p1->password, p2->password);
}

void sort_passwords(password_t passwords[], int count) {
    qsort(passwords, count, sizeof(password_t), compare_passwords);
}

int main() {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    password_t passwords[MAX_PASSWORDS];
    int count = 0;

    while (fscanf(file, "%s %s", passwords[count].name, passwords[count].password) == 2) {
        count++;
        if (count >= MAX_PASSWORDS) {
            break;
        }
    }

    fclose(file);

    sort_passwords(passwords, count);

    printf("Sorted passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }

    return 0;
}