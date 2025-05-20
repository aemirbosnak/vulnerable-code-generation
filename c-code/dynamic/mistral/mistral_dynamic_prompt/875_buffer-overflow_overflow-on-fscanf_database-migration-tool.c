#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void readData(char* buffer, int size) {
    printf("Enter data to migrate: ");
    fscanf(stdin, "%s", buffer);
}

void processData(char* data) {
    char temp[100];
    strcpy(temp, data);
    // Assuming some processing...
    printf("Processed data: %s\n", temp);
}

int main() {
    char data[5];
    readData(data, 5);
    processData(data);
    return 0;
}
