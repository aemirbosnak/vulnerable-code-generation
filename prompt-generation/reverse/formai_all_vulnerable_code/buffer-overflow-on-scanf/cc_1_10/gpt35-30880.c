//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct movie
{
  char title[50];
  float rating;
  struct movie *next;
};

// Function declarations
struct movie *createMovie(char[], float);
void addMovie(struct movie **, struct movie *);
void displayMovies(struct movie *);

int main()
{
  struct movie *head = NULL; // Head of linked list
  char title[50]; // Temporary storage for movie title
  float rating; // Temporary storage for movie rating
  char choice; // User's choice for continuing to add movies or not

  do
  {
    printf("Enter movie title: ");
    fgets(title, 50, stdin);
    // Remove newline character from title
    title[strcspn(title, "\n")] = 0;

    // Get rating
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &rating);
    while (getchar() != '\n'); // Clear input buffer

    // Create new movie and add to linked list
    struct movie *newMovie = createMovie(title, rating);
    addMovie(&head, newMovie);

    // Ask user if they want to add another movie
    printf("Do you want to add another movie? (y/n): ");
    scanf("%c", &choice);
    while (getchar() != '\n'); // Clear input buffer

    // Convert choice to lowercase before checking if user wants to continue
    choice = tolower(choice);  
  } while (choice == 'y');

  // Display all movies
  displayMovies(head);

  // Free memory allocated for linked list
  struct movie *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }

  return 0;
}

/* Function to create a new movie with given title and rating */
struct movie *createMovie(char title[], float rating)
{
  // Allocate memory for new movie
  struct movie *newMovie = (struct movie *)malloc(sizeof(struct movie));

  // Create movie with provided title and rating
  strcpy(newMovie->title, title);
  newMovie->rating = rating;
  newMovie->next = NULL;

  return newMovie;
}

/* Function to add a new movie to the end of the linked list */
void addMovie(struct movie **head, struct movie *newMovie)
{
  // If linked list is empty, make the new movie the head
  if (*head == NULL)
  {
    *head = newMovie;
  }
  // Otherwise, traverse to the end of the list and add the new movie
  else
  {
    struct movie *temp = *head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newMovie;
  }
}

/* Function to display all movies in linked list */
void displayMovies(struct movie *head)
{
  printf("\n");
  if (head == NULL)
  {
    printf("No movies to display.\n");
  }
  else
  {
    printf("Title\t\tRating\n");
    printf("-----\t\t------\n");
    while (head != NULL)
    {
      printf("%s\t\t%.1f\n", head->title, head->rating);
      head = head->next;
    }
  }
}