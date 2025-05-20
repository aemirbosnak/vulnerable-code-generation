//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char name[50];
    char value[1000];
} metadata;

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return 1;
    }
    
    metadata data[100];
    int count = 0;
    
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        int i = 0;
        while (line[i] != '\0' && line[i] != ':') {
            i++;
        }
        if (line[i] != ':') {
            continue;
        }
        
        strncpy(data[count].name, line, i);
        data[count].name[i] = '\0';
        
        strncpy(data[count].value, line + i + 2, strlen(line) - i - 3);
        data[count].value[strlen(line) - i - 3] = '\0';
        
        count++;
    }
    
    fclose(file);
    
    printf("\nMetadata:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", data[i].name, data[i].value);
    }
    
    return 0;
}