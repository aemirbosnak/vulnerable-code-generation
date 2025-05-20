//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_INSTRUCTION_SIZE 64
#define MAX_INSTRUCTION_COUNT 1000

typedef struct {
    char *name;
    int count;
} Instruction;

Instruction instructions[MAX_INSTRUCTION_COUNT];
int instruction_count = 0;

void add_instruction(char *name) {
    if (instruction_count == MAX_INSTRUCTION_COUNT) {
        printf("Error: Too many instructions.\n");
        exit(1);
    }

    Instruction *new_instruction = &instructions[instruction_count];
    new_instruction->name = strdup(name);
    new_instruction->count = 0;

    instruction_count++;
}

void read_file(FILE *file) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *instruction_name = strtok(line, " ");
        if (instruction_name == NULL) {
            continue;
        }

        char *instruction_args = strtok(NULL, " ");
        while (instruction_args!= NULL) {
            add_instruction(instruction_name);
            instruction_args = strtok(NULL, " ");
        }
    }
}

void print_instructions() {
    printf("Instructions:\n");
    for (int i = 0; i < instruction_count; i++) {
        printf("%s: %d\n", instructions[i].name, instructions[i].count);
    }
}

int main() {
    char filename[MAX_LINE_SIZE];
    printf("Enter the name of the file to analyze: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_file(file);
    fclose(file);

    print_instructions();

    return 0;
}