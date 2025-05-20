//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
// Claude Shannon Style Date Converter
#define BINARY_GROUP_SIZE 36

struct Date {
    int month;
    int day;
    int year;
};

int main() {
    struct Date inputDate;
    char dateString[11];

    printf("Enter date in format 'MM DD YYYY': ");
    scanf("%s", dateString);

    sscanf(dateString, "%d %d %d", &inputDate.month, &inputDate.day, &inputDate.year);

    // Convert month to binary
    int monthBinary[6];
    for (int i = 0; i < 6; i++) {
        monthBinary[5 - i] = inputDate.month / (int)pow(10, i) % 2;
        inputDate.month %= (int)pow(10, i);
    }

    // Convert day to binary
    int dayBinary[6];
    for (int i = 0; i < 6; i++) {
        dayBinary[5 - i] = inputDate.day / (int)pow(10, i) % 2;
        inputDate.day %= (int)pow(10, i);
    }

    // Convert year to binary
    int yearBinary[10];
    for (int i = 0; i < 10; i++) {
        yearBinary[9 - i] = inputDate.year / (int)pow(10, i) % 2;
        inputDate.year %= (int)pow(10, i);
    }

    printf("\nBinary representation of the given date:\n");

    // Print binary representation of month, day, and year in groups of 36 bits
    for (int i = 0; i < 3; i++) {
        printf("Month group %d: ", i + 1);
        for (int j = 0; j < 12; j++)
            printf("%d", monthBinary[j]);
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        printf("Day group %d: ", i + 1);
        for (int j = 0; j < 6; j++)
            printf("%d", dayBinary[j]);
        printf("\n");
    }

    for (int i = 0; i < 4; i++) {
        printf("Year group %d: ", i + 1);
        for (int j = 0; j < 10; j++)
            printf("%d", yearBinary[j]);
        printf("\n");
    }

    return 0;
}