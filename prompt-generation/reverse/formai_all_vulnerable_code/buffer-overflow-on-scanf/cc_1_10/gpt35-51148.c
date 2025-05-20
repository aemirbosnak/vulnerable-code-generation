//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: future-proof
#include<stdio.h>
#include<string.h>

//function to translate C Cat Language to English
void translate(char* c_cat) {
  char english[1000] = ""; //initialize empty string to store english translation
  int length = strlen(c_cat);

  //iterate through each character of C Cat input string
  for(int i=0; i<length; i++) {
    switch(c_cat[i]) {

      //case when cat says hello
      case 'm':
        strcat(english, "Hello ");
        break;

      //case when cat says goodbye
      case 'w':
        strcat(english, "Goodbye ");
        break;

      //case when cat wants food
      case 't':
        strcat(english, "I am hungry. Please give me food ");
        break;

      //case when cat is sleepy
      case 'p':
        strcat(english, "I am sleepy. I want to take a nap ");
        break;

      //case when cat is happy
      case 'c':
        strcat(english, "I am happy ");
        break;

      //case when cat is sad
      case 's':
        strcat(english, "I am sad ");
        break;

      //case for all other possibilities in C Cat language
      default:
        strcat(english, "I don't understand what you are saying ");
        break;
    }
  }

  //print out the translated string
  printf("%s\n", english);
}

int main() {
  char c_cat[1000]; //initialize C Cat input string
  printf("Enter C Cat language: ");
  scanf("%s", c_cat);

  //call the translation function
  translate(c_cat);

  return 0;
}