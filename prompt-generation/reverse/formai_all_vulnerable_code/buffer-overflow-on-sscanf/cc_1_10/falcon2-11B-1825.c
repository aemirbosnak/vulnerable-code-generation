//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} data_t;

int read_csv(const char *filename, data_t **data, int *n_data) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    data_t *d = *data;
    int n_read = 0;
    while ((read = getline(&line, &len, file))!= -1) {
        char *name = NULL;
        char *value = NULL;
        sscanf(line, "%s %s", &name, &value);
        if (strcmp(name, "Name") == 0) {
            d->name = value;
            n_read++;
        } else if (strcmp(name, "Value") == 0) {
            d->value = value;
            n_read++;
        } else {
            printf("Error: Unexpected field name\n");
            return -1;
        }
        free(name);
        free(value);
    }
    fclose(file);
    *n_data = n_read;
    return 0;
}

int main() {
    data_t *data = NULL;
    int n_data;
    read_csv("data.csv", &data, &n_data);
    if (n_data > 0) {
        for (int i = 0; i < n_data; i++) {
            printf("Name: %s, Value: %s\n", data[i].name, data[i].value);
        }
        free(data);
    } else {
        printf("No data found\n");
    }
    return 0;
}