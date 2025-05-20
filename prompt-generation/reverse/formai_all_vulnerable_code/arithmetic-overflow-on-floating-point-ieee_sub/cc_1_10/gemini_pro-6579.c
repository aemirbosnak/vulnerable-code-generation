//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: irregular
#define FANCY_AS_HECK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Colors for some fancy ASCII art
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define RESET "\x1b[0m"

// All the fancy ASCII art
char *welcome_banner =
"  _             _         _      ___    _            ____        _            ___   _         _ _ _       \n"
"| |           (_)       | |   / / \ \__/\| |          / ___|__  _ | |  ___    / _ \ | |  __ _ | || | |__  \n"
"| |__   ___   _   _ __  | |__/ /   \ /| | ___    ___ \___ \ \/ \| | / __|__ | (_) || | / _` || || '_ \  \n"
"| '_ \ / _ \ | | | '_ \ |  __  / \   / |/ _ \  / _ \___ \) |) |  \| \__ \___ \|  _  || || (_| || || | | | \n"
"| | | | (_) || | | | | || |  \ \  /| |\  __/ ||  __/ __/ /| | | |\  |___/___/ | | | || |\__, ||_||_| |_| |\n"
"|_| |_|\___/ |_| |_| |_||_|   \_\/ |_| \___|  \___|\__/ |_| |_| \_|\____/    |_| |_||_| |___/ \___/   \n";

char *menu_banner =
"#############################################################################################################################\n"
"#                                  $$$$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$   $$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$ #\n"
"#                                  $$$$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ #\n"
"#                                                                                                                               #\n"
"#############################################################################################################################\n\n"
"  ____        _   _    ____       ____            _ _  __  __     _   _      \n"
" |  _ \      | | | |  / __ \     |  _ \          | | |\/  \/  |   | | | |     \n"
" | |_) | __ _| |_| | | |  | | ___ | |_) | __ _  ___| | | \  /\  | __| |_| | ___ \n"
" |  __/ / _` | __| | | |  | |/ _ \|  __/ / _` |/ _ \ | | | |\/| | | __| __/ / _ \ \n"
" |_|   | (_| | |_| |_| |__| |\ (_) | |   | (_| |  __/ |_| | |  | | | |_| ||  __/ \n"
"                                 \___/          \__,_|\__/|_|  |_|  \__|\__| \___| \n\n";

char *goodbye_banner =
"  _    _ _______    _      __    __       __          __          __   \n"
" | |  | |__   __|  | |    / / /\ \ \ /\  / /         / /         / /   \n"
" | |__| |  | | __ _| | __/ /  \ \_/ /  \/ /  __  __ / /__  __  __/ /_   \n"
" |  __  |  | |/ _` | |/ _ \/ /\ \  /    /  / _ \/ _ \/ _ \/ _ \/ __/   \n"
" | |  | |  | | (_| | |  __/ /  \ \/ /\ \/  /  __/  __/  __/  __/\__ \   \n"
" |_|  |_|  |_|\__,_|_|\___\/    \/  \/    \___|\___|\___|\___|\___/   \n\n";

// Function to print the welcome banner
void print_welcome_banner() {
  printf("%s\n", welcome_banner);
}

// Function to print the menu banner
void print_menu_banner() {
  printf("%s\n", menu_banner);
}

// Function to print the goodbye banner
void print_goodbye_banner() {
  printf("%s\n", goodbye_banner);
}

// Function to get the user's input
int get_user_input(char *prompt) {
  int input;
  printf("%s", prompt);
  scanf("%d", &input);
  return input;
}

// Function to calculate the user's income
double calculate_income() {
  double income;
  printf("Enter your monthly income: ");
  scanf("%lf", &income);
  return income;
}

// Function to calculate the user's expenses
double calculate_expenses() {
  double expenses;
  printf("Enter your monthly expenses: ");
  scanf("%lf", &expenses);
  return expenses;
}

// Function to calculate the user's savings
double calculate_savings(double income, double expenses) {
  double savings = income - expenses;
  return savings;
}

// Function to print the user's financial report
void print_financial_report(double income, double expenses, double savings) {
  printf("## Financial Report ##\n");
  printf("Income: %s%.2lf%s\n", GREEN, income, RESET);
  printf("Expenses: %s%.2lf%s\n", RED, expenses, RESET);
  printf("Savings: %s%.2lf%s\n", YELLOW, savings, RESET);
}

// Main function
int main() {
  // Print the welcome banner
  print_welcome_banner();

  // Get the user's input
  int choice = get_user_input("Enter 1 to continue or 0 to quit: ");

  // Loop until the user quits
  while (choice != 0) {

    // Print the menu banner
    print_menu_banner();

    // Calculate the user's income
    double income = calculate_income();

    // Calculate the user's expenses
    double expenses = calculate_expenses();

    // Calculate the user's savings
    double savings = calculate_savings(income, expenses);

    // Print the user's financial report
    print_financial_report(income, expenses, savings);

    // Get the user's input
    choice = get_user_input("Enter 1 to continue or 0 to quit: ");
  }

  // Print the goodbye banner
  print_goodbye_banner();

  return 0;
}