//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a scientific data point
typedef struct DataPoint {
    double value;
    char unit[10];
    struct DataPoint* next;
} DataPoint;

// Function prototypes
DataPoint* createDataPoint(double value, const char* unit);
void appendDataPoint(DataPoint** head, double value, const char* unit);
void printDataPoints(DataPoint* head);
void freeDataPoints(DataPoint* head);
double calculateMean(DataPoint* head);
void sortDataPoints(DataPoint** head);
void displayMenu();

int main() {
    DataPoint* head = NULL;
    int choice;
    double value;
    char unit[10];

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%lf", &value);
                printf("Enter unit: ");
                scanf("%s", unit);
                appendDataPoint(&head, value, unit);
                break;
            case 2:
                printf("Data Points:\n");
                printDataPoints(head);
                break;
            case 3:
                printf("Mean of data points: %.2f\n", calculateMean(head));
                break;
            case 4:
                sortDataPoints(&head);
                printf("Data Points sorted.\n");
                break;
            case 5:
                freeDataPoints(head);
                head = NULL;
                printf("All data points freed.\n");
                break;
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
        printf("\n");
    } while (choice != 0);

    // Free allocated memory before exit
    freeDataPoints(head);
    return 0;
}

// Create a new data point with the given value and unit
DataPoint* createDataPoint(double value, const char* unit) {
    DataPoint* newPoint = (DataPoint*)malloc(sizeof(DataPoint));
    if (!newPoint) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newPoint->value = value;
    snprintf(newPoint->unit, sizeof(newPoint->unit), "%s", unit);
    newPoint->next = NULL;
    return newPoint;
}

// Append a new data point to the end of the linked list
void appendDataPoint(DataPoint** head, double value, const char* unit) {
    DataPoint* newPoint = createDataPoint(value, unit);
    if (*head == NULL) {
        *head = newPoint;
    } else {
        DataPoint* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPoint;
    }
}

// Print all the data points in the linked list
void printDataPoints(DataPoint* head) {
    DataPoint* current = head;
    if (current == NULL) {
        printf("No data points to display.\n");
        return;
    }
    while (current != NULL) {
        printf("Value: %.2f %s\n", current->value, current->unit);
        current = current->next;
    }
}

// Free all the allocated memory for the linked list
void freeDataPoints(DataPoint* head) {
    DataPoint* current = head;
    DataPoint* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

// Calculate the mean of the data points in the linked list
double calculateMean(DataPoint* head) {
    if (head == NULL) {
        return 0.0;
    }

    double sum = 0.0;
    int count = 0;
    DataPoint* current = head;

    while (current != NULL) {
        sum += current->value;
        count++;
        current = current->next;
    }
    return sum / count;
}

// Sort the data points in ascending order based on their values
void sortDataPoints(DataPoint** head) {
    if (*head == NULL) return;

    DataPoint* current;
    DataPoint* nextPoint;
    double tempValue;
    char tempUnit[10];

    for (current = *head; current->next != NULL; current = current->next) {
        for (nextPoint = current->next; nextPoint != NULL; nextPoint = nextPoint->next) {
            if (current->value > nextPoint->value) {
                // Swap values
                tempValue = current->value;
                current->value = nextPoint->value;
                nextPoint->value = tempValue;

                // Swap units
                snprintf(tempUnit, sizeof(tempUnit), "%s", current->unit);
                snprintf(current->unit, sizeof(current->unit), "%s", nextPoint->unit);
                snprintf(nextPoint->unit, sizeof(nextPoint->unit), "%s", tempUnit);
            }
        }
    }
}

// Display the menu options
void displayMenu() {
    printf("Menu:\n");
    printf("1. Add Data Point\n");
    printf("2. Display Data Points\n");
    printf("3. Calculate Mean\n");
    printf("4. Sort Data Points\n");
    printf("5. Free Data Points\n");
    printf("0. Exit\n");
    printf("Select an option: ");
}