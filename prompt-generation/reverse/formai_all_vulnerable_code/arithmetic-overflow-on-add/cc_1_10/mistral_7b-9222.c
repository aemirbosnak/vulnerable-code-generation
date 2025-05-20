//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define LOG_FILE "survival_log.txt"

typedef struct {
    char name[50];
    int health;
    int food;
} Survivor;

void write_survivor(FILE *log_file, Survivor survivor) {
    fprintf(log_file, "%s: Health = %d, Food = %d\n", survivor.name, survivor.health, survivor.food);
}

int main() {
    char line[MAX_LINE_LEN];
    FILE *log_file = fopen(LOG_FILE, "w+");

    if (log_file == NULL) {
        perror("Error opening file:");
        exit(1);
    }

    // Post-apocalyptic world
    Survivor john = {"John Doe", 50, 10};
    Survivor jane = {"Jane Doe", 70, 15};

    // Survivors' daily activities
    while (1) {
        // Hunt for food
        int food_obtained = rand() % 20 + 1;
        john.food += food_obtained;

        // Update log file
        write_survivor(log_file, john);

        // Rest and recover health
        john.health += rand() % 5 + 5;

        // Check for other survivors
        if (fgets(line, MAX_LINE_LEN, log_file) != NULL) {
            sscanf(line, "%s: Health = %d, Food = %d", jane.name, &jane.health, &jane.food);

            // Trade food for health
            if (jane.food < john.food && john.health < 100) {
                int food_exchanged = (jane.food + john.food) / 2;
                john.food -= food_exchanged;
                jane.food += food_exchanged;
                john.health += 10;

                // Update log file
                rewind(log_file);
                write_survivor(log_file, john);
                write_survivor(log_file, jane);
            }
        }

        // Survive another day
        usleep(100000);
    }

    fclose(log_file);
    return 0;
}