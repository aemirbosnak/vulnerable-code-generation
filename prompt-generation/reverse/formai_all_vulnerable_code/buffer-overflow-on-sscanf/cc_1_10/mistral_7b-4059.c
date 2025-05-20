//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct {
    char name[256];
    int age;
    char sex;
} Person;

int main(int argc, char *argv[]) {
    FILE *fp_in, *fp_out;
    char line[1024];
    int i;
    Person people[100];

    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    fp_in = fopen(argv[1], "r");
    if (fp_in == NULL) {
        perror("Error opening input file");
        return 1;
    }

    fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        perror("Error opening output file");
        fclose(fp_in);
        return 1;
    }

    while (fgets(line, sizeof(line), fp_in) != NULL) {
        sscanf(line, "%s%d%c", people[i].name, &people[i].age, &people[i].sex);
        i++;
    }
    rewind(fp_in); // Rewind the input file to the beginning

    for (i = 0; i < (fseek(fp_in, 0, SEEK_END) / sizeof(Person)); i++) {
        if (people[i].age % 2 == 0) {
            strcat(people[i].name, "_even");
        } else {
            strcat(people[i].name, "_odd");
        }
        fprintf(fp_out, "%s_aged_%d\n", people[i].name, people[i].age);
    }

    fclose(fp_in);
    fclose(fp_out);

    for (i = 0; i < 100; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}