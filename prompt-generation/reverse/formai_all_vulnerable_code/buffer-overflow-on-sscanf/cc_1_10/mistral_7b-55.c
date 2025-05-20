//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_SKILLS_LENGTH 100
#define MAX_LINES 10

// Structure to store resume data
struct knight {
    char name[MAX_NAME_LENGTH];
    char skills[MAX_SKILLS_LENGTH][MAX_NAME_LENGTH];
    int num_skills;
};

// Function to parse resume lines and fill the knight struct
void parse_line(char line[], struct knight *knight) {
    char field[MAX_NAME_LENGTH];
    char value[MAX_NAME_LENGTH];

    sscanf(line, "%s %s", field, value);

    if (strcmp(field, "Name") == 0) {
        strcpy(knight->name, value);
    } else if (strcmp(field, "Skill") == 0) {
        if (knight->num_skills < MAX_SKILLS_LENGTH) {
            strcpy(knight->skills[knight->num_skills], value);
            knight->num_skills++;
        }
    }
}

int main(int argc, char *argv[]) {
    char line[MAX_NAME_LENGTH + MAX_SKILLS_LENGTH + 50]; // enough for "Name: John Doe\nSkill: Swordsmanship\n"
    struct knight knight;
    int lines_parsed = 0;

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        parse_line(line, &knight);
        lines_parsed++;
    }

    fclose(fp);

    printf("Knight's Name: %s\n", knight.name);
    printf("Skills:\n");

    for (int i = 0; i < knight.num_skills; i++) {
        printf("- %s\n", knight.skills[i]);
    }

    return 0;
}