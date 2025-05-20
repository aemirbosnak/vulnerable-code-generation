#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_data(char input[]) {
    char buffer[10];
    scanf("%s", buffer);
    strcpy(input, buffer);
    printf("Processed data: %s\n", input);
}

int main() {
    char data[512];
    printf("Enter large data to overwrite the buffer:\n");
    process_data(data);
    return 0;
}
