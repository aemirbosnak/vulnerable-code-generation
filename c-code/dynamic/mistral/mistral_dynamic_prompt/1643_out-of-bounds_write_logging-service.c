#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void log_message(char *message) {
    char log_buffer[BUFFER_SIZE];
    snprintf(log_buffer, BUFFER_SIZE, "[%s] %s", __TIME__, message);
    FILE *log_file = fopen("log.txt", "a");
    fputs(log_buffer, log_file);
    fclose(log_file);
}

int main() {
    char user_input[256];
    printf("Enter log message: ");
    fgets(user_input, sizeof(user_input), stdin);

    log_message(user_input);

    // Deliberate out-of-bounds write vulnerability
    char *attacker_input = malloc(2 * sizeof(char));
    printf("Attacker Input: %s\n", attacker_input);
    strcpy(attacker_input, user_input);
    strcat(attacker_input, "A");
    printf("Attacker Input after modification: %s\n", attacker_input);

    return 0;
}
