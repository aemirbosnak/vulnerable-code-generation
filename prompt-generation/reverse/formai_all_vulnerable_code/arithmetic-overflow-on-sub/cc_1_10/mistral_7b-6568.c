//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 20
#define CHARSET_SIZE 62

// Function to generate random number
unsigned int knuth_random(void) {
  static unsigned long s = 123456789;
  static unsigned int t, a, b, c, d;
  unsigned int x;

  if (s == 123456789) {
    s = 161803398;
    t = 45761;
    a = 1414214053;
    b = 4294967293;
    c = 1;
  }

  x = s;
  s = x * a + c;
  c = b;
  b = x - (s / c);

  return (x = s % CHARSET_SIZE);
}

// Function to generate random password
char* generate_password(void) {
  static char password[LENGTH + 1];
  int i;

  for (i = 0; i < LENGTH; i++) {
    password[i] = (char)(knuth_random() % CHARSET_SIZE + 'a' - 10);
    if (knuth_random() % 2 == 0)
      password[i] = (char)(knuth_random() % CHARSET_SIZE + 'A' - 10);
    if (knuth_random() % 3 == 0)
      password[i] = (char)(knuth_random() % 10 + '0');
    if (knuth_random() % 5 == 0)
      password[i] = (char)(knuth_random() % 12 + '!');
    if (i == LENGTH - 1)
      password[i] = '\0';
  }

  return password;
}

// Function to print generated password
void print_password(char* password) {
  int i;

  printf("Generated Password: ");
  for (i = 0; password[i] != '\0'; i++) {
    printf("%c", password[i]);
  }
  printf("\n");
}

int main(void) {
  clock_t start = clock();
  char* password;

  srand((unsigned int)time(NULL));

  password = generate_password();
  print_password(password);

  free(password);

  clock_t end = clock();
  printf("Time taken to generate password: %f seconds\n",
         (float)(end - start) / CLOCKS_PER_SEC);

  return 0;
}