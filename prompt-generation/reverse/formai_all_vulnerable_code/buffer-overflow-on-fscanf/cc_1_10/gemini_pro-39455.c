//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records and the maximum length of each record
#define MAX_RECORDS 100
#define MAX_RECORD_LENGTH 100

// Define the structure of a record
typedef struct {
    char name[MAX_RECORD_LENGTH];
    int age;
    char gender;
} Record;

// Read the records from a file into an array
void read_records(Record records[], int *num_records, char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read the records from the file
    int i = 0;
    while (fscanf(file, "%s %d %c", records[i].name, &records[i].age, &records[i].gender) != EOF) {
        i++;
    }

    // Close the file
    fclose(file);

    // Set the number of records
    *num_records = i;
}

// Print the records to the console
void print_records(Record records[], int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("%s %d %c\n", records[i].name, records[i].age, records[i].gender);
    }
}

// Find the most common name in the records
char *find_most_common_name(Record records[], int num_records) {
    // Create an array to store the counts of each name
    int counts[MAX_RECORD_LENGTH];
    for (int i = 0; i < MAX_RECORD_LENGTH; i++) {
        counts[i] = 0;
    }

    // Count the occurrences of each name
    for (int i = 0; i < num_records; i++) {
        counts[records[i].name[0]]++;
    }

    // Find the name with the highest count
    int max_count = 0;
    char *most_common_name = NULL;
    for (int i = 0; i < MAX_RECORD_LENGTH; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            most_common_name = records[i].name;
        }
    }

    // Return the most common name
    return most_common_name;
}

// Find the average age of the records
float find_average_age(Record records[], int num_records) {
    // Calculate the total age of the records
    int total_age = 0;
    for (int i = 0; i < num_records; i++) {
        total_age += records[i].age;
    }

    // Calculate the average age
    float average_age = (float)total_age / num_records;

    // Return the average age
    return average_age;
}

// Find the most common gender in the records
char find_most_common_gender(Record records[], int num_records) {
    // Create an array to store the counts of each gender
    int counts[2];
    counts['M'] = 0;
    counts['F'] = 0;

    // Count the occurrences of each gender
    for (int i = 0; i < num_records; i++) {
        counts[records[i].gender]++;
    }

    // Find the gender with the highest count
    int max_count = 0;
    char most_common_gender = 'U';
    for (int i = 0; i < 2; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            most_common_gender = i == 0 ? 'M' : 'F';
        }
    }

    // Return the most common gender
    return most_common_gender;
}

// Main function
int main() {
    // Declare an array of records
    Record records[MAX_RECORDS];

    // Read the records from a file
    int num_records;
    read_records(records, &num_records, "records.txt");

    // Print the records to the console
    printf("Records:\n");
    print_records(records, num_records);

    // Find the most common name in the records
    char *most_common_name = find_most_common_name(records, num_records);
    printf("Most common name: %s\n", most_common_name);

    // Find the average age of the records
    float average_age = find_average_age(records, num_records);
    printf("Average age: %.2f\n", average_age);

    // Find the most common gender in the records
    char most_common_gender = find_most_common_gender(records, num_records);
    printf("Most common gender: %c\n", most_common_gender);

    return 0;
}