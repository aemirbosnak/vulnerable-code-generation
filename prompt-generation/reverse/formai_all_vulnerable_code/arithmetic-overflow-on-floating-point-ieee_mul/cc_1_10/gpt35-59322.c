//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>

/* Define variables for circuit */
double voltage;
double current;
double resistance;
double power;

/* Function to calculate power */
double calc_power(double voltage, double current) {
    return voltage * current;
}

/* Function to calculate current */
double calc_current(double voltage, double resistance) {
    return voltage / resistance;
}

/* Function to calculate voltage */
double calc_voltage(double current, double resistance) {
    return current * resistance;
}

/* Function to print circuit information */
void print_circuit_info() {
    printf("Circuit information:\n");
    printf("Voltage: %.2lf V\n", voltage);
    printf("Current: %.2lf A\n", current);
    printf("Resistance: %.2lf Ohm\n", resistance);
    printf("Power: %.2lf W\n", power);
}

/* Main function */
int main() {
    /* Prompt user for input */
    printf("Enter voltage: ");
    scanf("%lf", &voltage);
    printf("Enter resistance: ");
    scanf("%lf", &resistance);

    /* Calculate current and power */
    current = calc_current(voltage, resistance);
    power = calc_power(voltage, current);

    /* Calculate voltage using current and resistance */
    double calculated_voltage = calc_voltage(current, resistance);

    /* Print circuit information */
    print_circuit_info();

    /* Check if calculated voltage matches input voltage */
    if (voltage == calculated_voltage) {
        printf("Calculated voltage matches input voltage.\n");
    } else {
        printf("Calculated voltage does not match input voltage.\n");
    }

    return 0;
}