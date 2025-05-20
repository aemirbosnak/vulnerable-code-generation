//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits(const char *str) {
  while (*str) {
    if (!isdigit(*str)) {
      return 0;
    }
    str++;
  }
  return 1;
}

// Function to check if a string contains only letters
int is_letters(const char *str) {
  while (*str) {
    if (!isalpha(*str)) {
      return 0;
    }
    str++;
  }
  return 1;
}

// Function to check if a string contains only alphanumeric characters
int is_alphanumeric(const char *str) {
  while (*str) {
    if (!isalnum(*str)) {
      return 0;
    }
    str++;
  }
  return 1;
}

// Function to check if a string is a valid email address
int is_email(const char *str) {
  int at_count = 0;
  int dot_count = 0;
  while (*str) {
    if (*str == '@') {
      at_count++;
    } else if (*str == '.') {
      dot_count++;
    }
    str++;
  }
  return at_count == 1 && dot_count >= 1;
}

// Function to check if a string is a valid URL
int is_url(const char *str) {
  if (strncmp(str, "http://", 7) == 0 || strncmp(str, "https://", 8) == 0) {
    return 1;
  }
  return 0;
}

// Function to check if a string is a valid phone number
int is_phone(const char *str) {
  int digit_count = 0;
  while (*str) {
    if (isdigit(*str)) {
      digit_count++;
    }
    str++;
  }
  return digit_count == 10;
}

// Function to check if a string is a valid date
int is_date(const char *str) {
  int slash_count = 0;
  int digit_count = 0;
  while (*str) {
    if (*str == '/') {
      slash_count++;
    } else if (isdigit(*str)) {
      digit_count++;
    }
    str++;
  }
  return slash_count == 2 && digit_count == 8;
}

// Function to check if a string is a valid time
int is_time(const char *str) {
  int colon_count = 0;
  int digit_count = 0;
  while (*str) {
    if (*str == ':') {
      colon_count++;
    } else if (isdigit(*str)) {
      digit_count++;
    }
    str++;
  }
  return colon_count == 1 && digit_count == 4;
}

// Function to check if a string is a valid credit card number
int is_credit_card(const char *str) {
  int digit_count = 0;
  while (*str) {
    if (isdigit(*str)) {
      digit_count++;
    }
    str++;
  }
  return digit_count == 16;
}

int main() {
  char input[100];
  int choice;

  printf("Enter your choice:\n");
  printf("1. Check if a string contains only digits\n");
  printf("2. Check if a string contains only letters\n");
  printf("3. Check if a string contains only alphanumeric characters\n");
  printf("4. Check if a string is a valid email address\n");
  printf("5. Check if a string is a valid URL\n");
  printf("6. Check if a string is a valid phone number\n");
  printf("7. Check if a string is a valid date\n");
  printf("8. Check if a string is a valid time\n");
  printf("9. Check if a string is a valid credit card number\n");
  printf("10. Exit\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter a string: ");
      scanf("%s", input);
      if (is_digits(input)) {
        printf("The string contains only digits.\n");
      } else {
        printf("The string does not contain only digits.\n");
      }
      break;
    case 2:
      printf("Enter a string: ");
      scanf("%s", input);
      if (is_letters(input)) {
        printf("The string contains only letters.\n");
      } else {
        printf("The string does not contain only letters.\n");
      }
      break;
    case 3:
      printf("Enter a string: ");
      scanf("%s", input);
      if (is_alphanumeric(input)) {
        printf("The string contains only alphanumeric characters.\n");
      } else {
        printf("The string does not contain only alphanumeric characters.\n");
      }
      break;
    case 4:
      printf("Enter an email address: ");
      scanf("%s", input);
      if (is_email(input)) {
        printf("The email address is valid.\n");
      } else {
        printf("The email address is invalid.\n");
      }
      break;
    case 5:
      printf("Enter a URL: ");
      scanf("%s", input);
      if (is_url(input)) {
        printf("The URL is valid.\n");
      } else {
        printf("The URL is invalid.\n");
      }
      break;
    case 6:
      printf("Enter a phone number: ");
      scanf("%s", input);
      if (is_phone(input)) {
        printf("The phone number is valid.\n");
      } else {
        printf("The phone number is invalid.\n");
      }
      break;
    case 7:
      printf("Enter a date: ");
      scanf("%s", input);
      if (is_date(input)) {
        printf("The date is valid.\n");
      } else {
        printf("The date is invalid.\n");
      }
      break;
    case 8:
      printf("Enter a time: ");
      scanf("%s", input);
      if (is_time(input)) {
        printf("The time is valid.\n");
      } else {
        printf("The time is invalid.\n");
      }
      break;
    case 9:
      printf("Enter a credit card number: ");
      scanf("%s", input);
      if (is_credit_card(input)) {
        printf("The credit card number is valid.\n");
      } else {
        printf("The credit card number is invalid.\n");
      }
      break;
    case 10:
      exit(0);
    default:
      printf("Invalid choice. Please enter a valid choice.\n");
  }

  return 0;
}