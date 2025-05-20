#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void read_record(char *buffer, int record_id) {
    if (record_id < 0 || record_id >= 10000) {
        printf("Invalid record ID\n");
        return;
    }

    sprintf(buffer, "Record %d: [secret_data]", record_id);

    // Intentionally read past the allocated buffer
    printf("%s%.*s\n", buffer, MAX_INPUT_LENGTH + 1, buffer);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int record_id;

    printf("Enter the record ID to display: ");
    scanf("%d", &record_id);

    read_record(input, record_id);

    return 0;
}
