#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[1];
    char email[100];
    int age;
} User;

void read_user(User* user, FILE* file) {
    fscanf(file, "%s %s %d", user->name, user->email, &user->age);
}

void write_user(User* user, FILE* file) {
    fprintf(file, "%s %s %d", user->name, user->email, user->age);
}

void migrate_database(const char* input, const char* output) {
    FILE* in = fopen(input, "r");
    FILE* out = fopen(output, "w");

    User user;
    while (fgets(user.name, sizeof(user.name), in)) {
        read_user(&user, in);
        write_user(&user, out);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    migrate_database(argv[1], argv[2]);
    return 0;
}
