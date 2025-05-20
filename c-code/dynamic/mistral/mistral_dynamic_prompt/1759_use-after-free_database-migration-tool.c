#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char name[100];
    char address[200];
    int age;
} Record;

Record* load_data(const char* filename) {
    FILE* file = fopen(filename, "r");
    Record* data = NULL;
    Record tmp;
    int count = 0;

    while (fscanf(file, "%s %s %d", tmp.name, tmp.address, &tmp.age) == 3) {
        data = realloc(data, sizeof(Record) * ++count);
        data[count - 1] = tmp;
    }

    free(data);
    data = realloc(data, sizeof(Record) * count);

    return data;
}

void save_data(Record* data, const char* filename, int count) {
    FILE* file = fopen(filename, "w");

    for (int i = 0; i < count; ++i) {
        fprintf(file, "%s %s %d\n", data[i].name, data[i].address, data[i].age);
    }

    free(data);
}

void migrate(const char* input_filename, const char* output_filename) {
    Record* data = load_data(input_filename);
    save_data(data, output_filename, strlen(input_filename) + 1);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    migrate(argv[1], argv[2]);
    return 0;
}
