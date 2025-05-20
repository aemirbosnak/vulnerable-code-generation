#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

void migrate_data(char* input_data) {
    char data[200];
    strcpy(data, input_data);
    char* user_input = data + strlen(data);

    // User-supplied input
    printf("Enter migration configuration:\n");
    scanf("%s", user_input);

    // Process the user input...
    // (For the sake of this example, assume we have an out-of-bounds read vulnerability here)
    printf("Configured database migration. Starting migration...\n");

    // Simulate migration progress
    for (int i = 0; i < 10; ++i) {
        printf("Migrating... %d%%\n", i * 10);
        sleep(1);
    }

    printf("Migration complete.\n");
}

int main() {
    printf("Database Migration Tool\n");

    char input_data[MAX_INPUT_SIZE];
    printf("Enter data to migrate:\n");
    scanf("%s", input_data);

    migrate_data(input_data);

    return 0;
}
