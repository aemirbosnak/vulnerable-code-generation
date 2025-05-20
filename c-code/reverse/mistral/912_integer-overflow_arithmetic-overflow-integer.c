#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 256
#define DATE_FORMAT "%Y%m%d_%H%M%S"

void generate_backup_filename(char *output, const char *base_name) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    snprintf(output, BUFFER_SIZE, "%s%s", base_name, DATE_FORMAT);
    snprintf(output + strlen(output), BUFFER_SIZE - strlen(output), "_%02d", tm_now->tm_mday + 32 * (tm_now->tm_year % 100));
}

int main() {
    char filename[BUFFER_SIZE];
    generate_backup_filename(filename, "backup_");

    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "Backing up data...\n");
        fclose(file);
    } else {
        printf("Error creating file: %s\n", filename);
    }

    return 0;
}
