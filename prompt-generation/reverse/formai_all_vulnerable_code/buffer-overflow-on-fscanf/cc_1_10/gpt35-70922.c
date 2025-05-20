//FormAI DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20
#define PASSWORD_FILE "passwords.txt"
#define PASSWORD_STATS_FILE "password_stats.txt"

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char value[MAX_PASSWORD_LENGTH];
};

typedef struct password Password;

int num_passwords = 0;

Password passwords[MAX_PASSWORDS];

void read_passwords() {
    FILE* file = fopen(PASSWORD_FILE, "r");

    char name[MAX_PASSWORD_LENGTH];
    char value[MAX_PASSWORD_LENGTH];
    while (fscanf(file, "%s %s", name, value) == 2) {
        if (num_passwords == MAX_PASSWORDS) {
            printf("Error: too many passwords\n");
            exit(1);
        }
        strcpy(passwords[num_passwords].name, name);
        strcpy(passwords[num_passwords].value, value);
        num_passwords++;
    }

    fclose(file);
}

void write_passwords() {
    FILE* file = fopen(PASSWORD_FILE, "w");

    for (int i = 0; i < num_passwords; i++) {
        fprintf(file, "%s %s\n", passwords[i].name, passwords[i].value);
    }

    fclose(file);
}

int find_password_index(char* name) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_password(char* name, char* value) {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: too many passwords\n");
        exit(1);
    }
    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].value, value);
    num_passwords++;
    printf("Password added: %s\n", name);
    write_passwords();
}

void delete_password(char* name) {
    int index = find_password_index(name);
    if (index == -1) {
        printf("Error: password not found\n");
        return;
    }
    printf("Password deleted: %s\n", name);
    num_passwords--;
    for (int i = index; i < num_passwords; i++) {
        strcpy(passwords[i].name, passwords[i+1].name);
        strcpy(passwords[i].value, passwords[i+1].value);
    }
    write_passwords();
}

void view_password(char* name) {
    int index = find_password_index(name);
    if (index == -1) {
        printf("Error: password not found\n");
        return;
    }
    printf("%s: %s\n", name, passwords[index].value);
}

void generate_password(char* name) {
    char value[MAX_PASSWORD_LENGTH];
    srand(time(NULL));
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        value[i] = rand() % 94 + 33;
    }
    value[MAX_PASSWORD_LENGTH - 1] = '\0';
    add_password(name, value);
}

void print_stats() {
    FILE* file = fopen(PASSWORD_STATS_FILE, "w");

    fprintf(file, "Number of passwords: %d\n", num_passwords);

    int length_counts[MAX_PASSWORD_LENGTH] = {0};
    for (int i = 0; i < num_passwords; i++) {
        int length = strlen(passwords[i].value);
        length_counts[length]++;
    }

    fprintf(file, "Password length frequencies:\n");
    for (int i = 1; i < MAX_PASSWORD_LENGTH; i++) {
        fprintf(file, "Length %2d: %3d\n", i, length_counts[i]);
    }

    fclose(file);
}

int main() {
    read_passwords();

    while (1) {
        printf("Enter a command (add, delete, view, generate, stats, quit): ");
        char command[MAX_PASSWORD_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_PASSWORD_LENGTH];
            char value[MAX_PASSWORD_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter value: ");
            scanf("%s", value);
            add_password(name, value);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_PASSWORD_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            delete_password(name);
        } else if (strcmp(command, "view") == 0) {
            char name[MAX_PASSWORD_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            view_password(name);
        } else if (strcmp(command, "generate") == 0) {
            char name[MAX_PASSWORD_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            generate_password(name);
        } else if (strcmp(command, "stats") == 0) {
            print_stats();
        } else if (strcmp(command, "quit") == 0) {
            return 0;
        } else {
            printf("Error: unknown command\n");
        }
    }
}