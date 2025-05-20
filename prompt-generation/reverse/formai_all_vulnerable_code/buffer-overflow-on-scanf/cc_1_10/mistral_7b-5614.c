//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: introspective
#define F_TO_C(x) ((x - 32) * 5 / 9)
#define C_TO_F(x) ((x * 9 / 5) + 32)

#define INPUT_SIZE 100
#define MIN_TEMP -50
#define MAX_TEMP 200

void print_menu() {
    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");
}

int main() {
    double temperature, result;
    char choice;

    while (1) {
        print_menu();
        scanf("%c", &choice);

        if (choice == '1') {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);

            if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
                printf("Invalid temperature. Temperature must be between -50 and 200 degrees Fahrenheit.\n");
                continue;
            }

            result = F_TO_C(temperature);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, result);
        } else if (choice == '2') {
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);

            if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
                printf("Invalid temperature. Temperature must be between -50 and 200 degrees Celsius.\n");
                continue;
            }

            result = C_TO_F(temperature);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, result);
        } else if (choice == '3') {
            printf("Exiting the Temperature Converter...\n");
            break;
        } else {
            printf("Invalid option. Please choose a valid option.\n");
        }
    }

    return 0;
}