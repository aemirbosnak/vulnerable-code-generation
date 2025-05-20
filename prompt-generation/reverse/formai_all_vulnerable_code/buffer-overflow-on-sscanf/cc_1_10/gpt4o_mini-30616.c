//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100
#define MAX_FEATURES 10
#define MAX_LINE_LENGTH 256

// Struct for data record
typedef struct {
    int id;
    float features[MAX_FEATURES];
    char label[20];
} DataRecord;

// Function declarations
void load_data(const char *filename, DataRecord records[], int *num_records);
void print_data(DataRecord records[], int num_records);
void normalize_data(DataRecord records[], int num_records);
float calculate_distance(DataRecord a, DataRecord b, int num_features);
void classify(DataRecord train_set[], int num_train, DataRecord test_record, int k);

int main() {
    DataRecord records[MAX_RECORDS];
    int num_records = 0;
    
    // 1. Load data from file
    load_data("data.txt", records, &num_records);
    
    // 2. Print original data
    printf("\nOriginal Data:\n");
    print_data(records, num_records);
    
    // 3. Normalize data
    normalize_data(records, num_records);
    
    // 4. Print normalized data
    printf("\nNormalized Data:\n");
    print_data(records, num_records);
    
    // 5. Classify a random test record
    DataRecord test_record = {99, {0.5, 0.7, 0.8}, ""}; // Example test record
    int k = 3; // Number of neighbors
    printf("\nClassifying Test Record:\n");
    classify(records, num_records, test_record, k);
    
    return 0;
}

// Load data from a CSV file
void load_data(const char *filename, DataRecord records[], int *num_records) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) && *num_records < MAX_RECORDS) {
        sscanf(line, "%d,%f,%f,%f,%s", &records[*num_records].id,
               &records[*num_records].features[0],
               &records[*num_records].features[1],
               &records[*num_records].features[2],
               records[*num_records].label);
        (*num_records)++;
    }
    
    fclose(file);
}

// Print data records
void print_data(DataRecord records[], int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("ID: %d, Features: [", records[i].id);
        for (int j = 0; j < MAX_FEATURES; j++) {
            printf("%f", records[i].features[j]);
            if (j < MAX_FEATURES - 1) printf(", ");
        }
        printf("], Label: %s\n", records[i].label);
    }
}

// Normalize the feature data to [0, 1]
void normalize_data(DataRecord records[], int num_records) {
    for (int j = 0; j < MAX_FEATURES; j++) {
        float min_val = records[0].features[j];
        float max_val = records[0].features[j];
        
        // Finding min and max
        for (int i = 1; i < num_records; i++) {
            if (records[i].features[j] < min_val) min_val = records[i].features[j];
            if (records[i].features[j] > max_val) max_val = records[i].features[j];
        }
        
        // Normalizing
        for (int i = 0; i < num_records; i++) {
            records[i].features[j] = (records[i].features[j] - min_val) / (max_val - min_val);
        }
    }
}

// Calculate distance between two data records
float calculate_distance(DataRecord a, DataRecord b, int num_features) {
    float distance = 0.0f;
    for (int i = 0; i < num_features; i++) {
        distance += (a.features[i] - b.features[i]) * (a.features[i] - b.features[i]);
    }
    return sqrt(distance);
}

// Classify a test record using k-NN algorithm
void classify(DataRecord train_set[], int num_train, DataRecord test_record, int k) {
    float distances[MAX_RECORDS];
    for (int i = 0; i < num_train; i++) {
        distances[i] = calculate_distance(train_set[i], test_record, MAX_FEATURES);
    }
    
    // Find the k closest neighbors
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < num_train; j++) {
            if (distances[j] < distances[i]) {
                float temp_distance = distances[i];
                distances[i] = distances[j];
                distances[j] = temp_distance;
            }
        }
    }
    
    // Voting mechanism
    int labels_count[10] = {0}; // Assuming a maximum of 10 different labels
    for (int i = 0; i < k; i++) {
        int label = train_set[i].label[0] - '0'; // Convert char to int (assumes labels are single digits)
        labels_count[label]++;
    }

    // Determine the most frequent label
    int max_count = 0, predicted_label = -1;
    for (int i = 0; i < 10; i++) {
        if (labels_count[i] > max_count) {
            max_count = labels_count[i];
            predicted_label = i;
        }
    }
    
    printf("Predicted label for test record ID %d is: %d\n", test_record.id, predicted_label);
}