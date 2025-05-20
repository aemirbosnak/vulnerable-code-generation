#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void log_message(char* message) {
    FILE* log_file = fopen("app_logs.log", "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    char* user_name = getenv("USER");
    if (user_name == NULL) {
        fprintf(log_file, "Anonymous user executed operation\n");
    } else {
        fprintf(log_file, "%s executed operation: %s\n", user_name, message);
    }

    fclose(log_file);
}

int main(int argc, char* argv[]) {
    char* message = argv[1];

    // Deliberate invalid pointer dereference
    char* null_pointer = (char*)0xdeadbeef;
    printf("%c\n", *null_pointer);

    log_message(message);

    return 0;
}
