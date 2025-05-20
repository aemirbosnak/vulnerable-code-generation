//GEMINI-pro DATASET v1.0 Category: File handling ; Style: satisfied
// A whimsical C program to explore the realm of file handling with a touch of enchantment.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A function to conjure up a random name for our mysterious tome.
char *generateTomeName() {
  srand(time(NULL)); // Sowing the seeds of randomness.

  char *name[6] = {"Tome of Secrets", "Book of Enchantments", "Grimoire of Shadows",
                     "Alchemist's Codex", "Scroll of Destiny", "Tome of Lore"};
  int index = rand() % 6; // Choosing our random tome.

  char *tomeName = malloc(strlen(name[index]) + 1); // Allocating memory for the tome's name.
  strcpy(tomeName, name[index]); // Bestowing the tome with its name.

  return tomeName; // Returning the tome's name to the caller.
}

int main() {
  // A magical invocation to create our mysterious tome.
  char *tomeName = generateTomeName();
  printf("Behold! A tome of secrets emerges, named '%s'.\n", tomeName);

  // Opening the tome's pages, ready to inscribe our wisdom.
  FILE *tome = fopen(tomeName, "w");
  if (tome == NULL) { // Checking if the tome was successfully opened.
    printf("Alas, the tome could not be opened. A cruel twist of fate!\n");
    return EXIT_FAILURE;
  }

  // With trembling hands, we pen our profound thoughts into the tome.
  fprintf(tome, "Within these pages, knowledge and secrets shall dwell,\n"
                  "A testament to wisdom, a tale to be told.\n"
                  "Of ancient lore and forgotten realms,\n"
                  "The tome shall whisper, in whispers and spells.\n");

  // Sealing the tome with a mystical incantation.
  fclose(tome);
  printf("The tome has been sealed, its secrets safe within.\n");

  // Summoning a brave adventurer to embark on a quest to retrieve the tome.
  char adventurerName[50];
  printf("Enter the name of the intrepid adventurer who shall seek the tome: ");
  scanf("%s", adventurerName);

  // The adventurer embarks on their perilous journey.
  FILE *adventurerLog = fopen("Adventurer's Log.txt", "w");
  if (adventurerLog == NULL) { // Ensuring the log is ready for the adventurer's tale.
    printf("The adventurer's log could not be prepared. Fate plays a cruel hand.\n");
    return EXIT_FAILURE;
  }

  fprintf(adventurerLog, "Thus begins the tale of %s, the intrepid adventurer,\n"
                        "In search of the Tome of Secrets, a treasure to be found.\n"
                        "Through treacherous paths and forgotten realms,\n"
                        "Their journey shall unfold, in these written realms.\n",
          adventurerName);

  // The adventurer returns, the tome in their weary hands.
  fclose(adventurerLog);
  printf("The adventurer has returned, the tome in their possession.\n");

  // Unsealing the tome's secrets, revealing its hidden wisdom.
  tome = fopen(tomeName, "r");
  if (tome == NULL) { // Verifying the tome can be opened.
    printf("The tome cannot be opened. The secrets remain hidden.\n");
    return EXIT_FAILURE;
  }

  char line[256];
  while (fgets(line, sizeof(line), tome) != NULL) { // Delving into the tome's secrets.
    printf("%s", line); // Revealing the tome's wisdom to the world.
  }

  // Closing the tome, its secrets now shared with all.
  fclose(tome);
  printf("The tome has been closed, its wisdom spread far and wide.\n");

  // Releasing the adventurer from their arduous quest.
  printf("May %s's name be forever etched in the annals of legend,\n"
         "Their journey a testament to courage and perseverance.\n",
         adventurerName);

  // Destroying the tome, its secrets forever lost.
  remove(tomeName);
  printf("The tome has been destroyed, its secrets forever lost to time.\n");

  // As the tale ends, a sense of wonder and mystery lingers in the air.
  printf("And so, the adventure concludes, a tale woven in magic and lore,\n"
         "A testament to the power of imagination and the secrets that lie in store.\n");

  free(tomeName); // Releasing the memory of the tome's name.

  return EXIT_SUCCESS;
}