//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Constants
#define MAX_PASS_LEN 25
#define MIN_PASS_LEN 8
#define NUM_SPECIAL_CHARS 7
#define ASCII_LOWERCASE_START 97
#define ASCII_LOWERCASE_END 122
#define ASCII_UPPERCASE_START 65
#define ASCII_UPPERCASE_END 90
#define ASCII_NUMBER_START 48
#define ASCII_NUMBER_END 57
#define SPECIAL_CHARS "!#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

// Function Prototypes
int isValidInput(char*, char*);
int getRandNum(int, int);
char getRandChar(int, int);
int isCharInArray(char, char*, int);
void generatePassword(char*, int, int, int, int, int, int, int, int);
void shuffleArray(char*, int);

// Main Function
int main(){

  // Seed the random generator
  srand(time(NULL));

  // Initialize variables
  char password[MAX_PASS_LEN+1] = "";
  int len = -1, num_upper = -1, num_lower = -1, num_number = -1, num_special = -1;

  // Get input from user
  char input[50] = "";
  printf("Enter password length (at least 8 characters): ");
  scanf("%s", input);

  if(isValidInput(input, "password length")){
    len = atoi(input);
  }
  else{
    printf("Invalid input. The password length must be at least %d characters.\n", MIN_PASS_LEN);
    return 1;
  }

  printf("Enter number of uppercase letters (at least 1): ");
  scanf("%s", input);

  if(isValidInput(input, "number of uppercase letters")){
    num_upper = atoi(input);
  }
  else{
    printf("Invalid input. The number of uppercase letters must be at least 1.\n");
    return 1;
  }

  printf("Enter number of lowercase letters (at least 1): ");
  scanf("%s", input);

  if(isValidInput(input, "number of lowercase letters")){
    num_lower = atoi(input);
  }
  else{
    printf("Invalid input. The number of lowercase letters must be at least 1.\n");
    return 1;
  }

  printf("Enter number of numbers (at least 1): ");
  scanf("%s", input);

  if(isValidInput(input, "number of numbers")){
    num_number = atoi(input);
  }
  else{
    printf("Invalid input. The number of numbers must be at least 1.\n");
    return 1;
  }

  printf("Enter number of special characters (at least 1): ");
  scanf("%s", input);

  if(isValidInput(input, "number of special characters")){
    num_special = atoi(input);
  }
  else{
    printf("Invalid input. The number of special characters must be at least 1.\n");
    return 1;
  }

  // Check that the lengths add up to the desired length
  if((num_upper + num_lower + num_number + num_special) != len){
    printf("Invalid input. The lengths of the letters, numbers, and special characters must add up to the password length.\n");
    return 1;
  }

  // Generate the password
  generatePassword(password, len, num_upper, num_lower, num_number, num_special, ASCII_LOWERCASE_START, ASCII_LOWERCASE_END, ASCII_UPPERCASE_START);

  // Print the password
  printf("Your generated password is: %s", password);

  return 0;
}

// Check if the input is valid
int isValidInput(char* input, char* name){
  int len = strlen(input);
  for(int i = 0; i < len; i++){
    if(!isdigit(input[i])){
      return 0;
    }
  }
  if(atoi(input) < 1){
    return 0;
  }
  return 1;
}

// Get a random number between min and max (inclusive)
int getRandNum(int min, int max){
  return (rand() % (max - min + 1)) + min;
}

// Get a random character between ascii_start and ascii_end (inclusive)
char getRandChar(int ascii_start, int ascii_end){
  return (char)getRandNum(ascii_start, ascii_end);
}

// Check if a character is in an array
int isCharInArray(char c, char* arr, int len){
  for(int i = 0; i < len; i++){
    if(arr[i] == c){
      return 1;
    }
  }
  return 0;
}

// Generate the password
void generatePassword(char* password, int len, int num_upper, int num_lower, int num_number, int num_special, int ascii_lowercase_start, int ascii_lowercase_end, int ascii_uppercase_start){
  // Fill the password with lowercase letters
  for(int i = 0; i < num_lower; i++){
    password[i] = getRandChar(ascii_lowercase_start, ascii_lowercase_end);
  }

  // Fill the password with uppercase letters
  for(int i = num_lower; i < num_lower + num_upper; i++){
    password[i] = getRandChar(ascii_uppercase_start, ascii_uppercase_start + (ascii_lowercase_end - ascii_lowercase_start));
  }

  // Fill the password with numbers
  for(int i = num_lower + num_upper; i < num_lower + num_upper + num_number; i++){
    password[i] = getRandChar(ASCII_NUMBER_START, ASCII_NUMBER_END);
  }

  // Fill the password with special characters
  char special_chars[NUM_SPECIAL_CHARS] = SPECIAL_CHARS;
  for(int i = num_lower + num_upper + num_number; i < len; i++){
    char c = getRandChar(33, 126);
    while(isCharInArray(c, special_chars, NUM_SPECIAL_CHARS)){
      c = getRandChar(33, 126);
    }
    password[i] = c;
  }

  // Shuffle the password
  shuffleArray(password, len);
}

// Shuffle an array
void shuffleArray(char* arr, int len){
  for(int i = len - 1; i > 0; i--){
    int j = getRandNum(0, i);
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}