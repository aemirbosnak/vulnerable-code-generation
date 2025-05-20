//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100

struct password_entry {
    char site[50];
    char username[50];
    char password[100];
};

void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int compare_entries(const void* a, const void* b) {
    const struct password_entry* entry1 = (const struct password_entry*) a;
    const struct password_entry* entry2 = (const struct password_entry*) b;
    return strcmp(entry1->site, entry2->site);
}

void print_entry(const struct password_entry* entry) {
    printf("Site: %s\n", entry->site);
    printf("Username: %s\n", entry->username);
    printf("Password: %s\n\n", entry->password);
}

void sort_entries(struct password_entry* entries, int num_entries) {
    qsort(entries, num_entries, sizeof(struct password_entry), compare_entries);
}

int main() {
    FILE* file;
    struct password_entry entries[MAX_PASSWORDS];
    int num_entries = 0;
    char filename[50];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s %s", entries[num_entries].site, entries[num_entries].username, entries[num_entries].password)!= EOF) {
        num_entries++;
        if (num_entries >= MAX_PASSWORDS) {
            printf("Error: too many entries in file.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    sort_entries(entries, num_entries);

    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
    }

    return 0;
}