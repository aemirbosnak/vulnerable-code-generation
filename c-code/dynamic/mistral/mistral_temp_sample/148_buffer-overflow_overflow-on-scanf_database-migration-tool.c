#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void migrate_data(char *input_file, char *output_file) {
    FILE *input, *output;
    char buffer[BUFFER_SIZE];
    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    while (fgets(buffer, BUFFER_SIZE, input)) {
        fprintf(output, "%s", buffer);
    }

    fclose(input);
    fclose(output);

    char user_input[10];
    printf("Enter the name of the next input file: ");
    scanf("%s", user_input);

    // Deliberate buffer overflow
    char extra_data[1000];
    strcpy(extra_data, "Excessive data to trigger buffer overflow");
    strcat(user_input, extra_data);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: migration_tool input_file output_file\n");
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    return 0;
}
