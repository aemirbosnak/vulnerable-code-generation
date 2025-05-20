//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

/* declare a struct to store the data from the XML */
struct my_data {
    char name[50];
    int age;
    char gender[10];
};

/* function to parse the XML and fill in the struct */
void parse_xml(struct my_data *data, char *filename) {
    /* open the file */
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    /* read the file line by line */
    char line[100];
    int count = 0;
    while (fgets(line, 100, fp) != NULL) {
        /* extract the data */
        if (strstr(line, "<name>") != NULL) {
            sscanf(line, "<name>%[^<]</name>", data->name);
        } else if (strstr(line, "<age>") != NULL) {
            sscanf(line, "<age>%d</age>", &data->age);
        } else if (strstr(line, "<gender>") != NULL) {
            sscanf(line, "<gender>%[^<]</gender>", data->gender);
        }
        count++;
    }

    /* close the file */
    fclose(fp);

    /* check if all data was read */
    if (count != 3) {
        printf("Unable to parse XML\n");
        exit(1);
    }
}

/* main function for testing */
int main() {
    struct my_data data;
    parse_xml(&data, "data.xml");

    /* print the data */
    printf("Name: %s\nAge: %d\nGender: %s\n", data.name, data.age, data.gender);

    return 0;
}