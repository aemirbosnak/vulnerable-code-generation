//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
/* Hello there, welcome to my cheerful program on Memory management in C! */
#include <stdio.h>
#include <stdlib.h>

/* Let's create a struct to hold some relevant information */
typedef struct {
  int id;
  char *name;
  float height;
} person;

int main() {
  int num_people; /* Number of people to allocate memory for */
  person *people_ptr; /* Pointer to person struct */
  
  /* Let's greet the user and prompt them for input */
  printf("Hey there! How many people would you like to add?\n");
  scanf("%d", &num_people);

  /* Use malloc to allocate memory dynamically for people_ptr */
  people_ptr = (person*) malloc(num_people * sizeof(person));

  if (people_ptr == NULL) { /* If malloc failed */
    printf("Oh no, not enough memory!\n");
    exit(1); /* Exit program with error */
    /* Don't worry, we'll catch this error in the next step */
  }

  printf("Great! Let's start adding some people.\n");

  /* Prompt the user to add a person's details */
  for(int i=0; i<num_people; i++) {
    printf("Person #%d:\n", i+1);
    printf("ID: ");
    scanf("%d", &people_ptr[i].id);
    printf("Name: ");
    
    /* Use malloc to allocate memory for name dynamically */
    people_ptr[i].name = (char*) malloc(20 * sizeof(char));

    if (people_ptr[i].name == NULL) { /* If malloc failed */
      printf("Oops, ran out of memory for names!\n");
      /* No need to exit, we can carry on with the program and skip adding names */
    } else {
      scanf("%s", people_ptr[i].name);
    }

    printf("Height in meters: ");
    scanf("%f", &people_ptr[i].height);
    printf("\n");
  }

  /* Finally, let's print out all the entered details */
  printf("Great job! Here are all the details you've entered:\n");
  for(int i=0; i<num_people; i++) {
    printf("Person #%d: ID: %d | Name: %s | Height: %.2f m\n", i+1, people_ptr[i].id, people_ptr[i].name, people_ptr[i].height);
  }

  /* Free up all dynamically allocated memory before exiting program */
  for(int i=0; i<num_people; i++) {
    free(people_ptr[i].name);
  }
  free(people_ptr);

  printf("\nAll done! Thanks for using my program. :)");
  return 0;
}