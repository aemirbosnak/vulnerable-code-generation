//GEMINI-pro DATASET v1.0 Category: Educational ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A gentle reminder to embrace the present moment.
void seize_the_day() {
  printf("Time waits for no one.\n"
         "Make the most of this fleeting moment.\n"
         "For tomorrow is but a dream of today.\n\n");
}

// A serene melody to calm the weary soul.
void play_serenade() {
  printf("Amidst the gentle sway of willows,\n"
         "A melody unfolds, soft and low.\n"
         "Each note caresses the heart with grace,\n"
         "Whispering secrets of a tranquil embrace.\n\n");
}

// A tranquil haven where weary thoughts can find solace.
void paint_the_meadow() {
  printf("In the realm of verdant meadows,\n"
         "Where daisies dance and poppies gleam,\n"
         "A canvas painted with hues of serenity,\n"
         "Inviting weary souls to find their dream.\n\n");
}

// A soothing lullaby to guide us gently into slumber.
void sing_the_nightingale() {
  printf("As twilight's embrace enfolds the land,\n"
         "A songbird's melody fills the air.\n"
         "With gentle trills and whispered serenades,\n"
         "The nightingale lulls us into peaceful slumber's lair.\n\n");
}

// A moment of introspection and self-discovery.
void seek_inner_wisdom() {
  printf("In the depths of silence, find your voice,\n"
         "A journey inward, a whispered choice.\n"
         "Embrace the whispers of your tranquil soul,\n"
         "And let your inner wisdom make you whole.\n\n");
}

int main() {
  // A gentle welcome to our tranquil haven.
  printf("Welcome, weary traveler, to this oasis of calm.\n"
         "May these gentle whispers soothe your soul and guide you to inner peace.\n\n");

  // A symphony of serenity to accompany your journey.
  srand(time(NULL));
  int choice;
  while (1) {
    printf("Choose a path to tranquility:\n"
           "1. Seize the Day\n"
           "2. Play a Serenade\n"
           "3. Paint the Meadow\n"
           "4. Sing the Nightingale\n"
           "5. Seek Inner Wisdom\n"
           "6. Exit\n>> ");
    scanf("%d", &choice);

    // Navigate the gentle paths of serenity.
    switch (choice) {
      case 1:
        seize_the_day();
        break;
      case 2:
        play_serenade();
        break;
      case 3:
        paint_the_meadow();
        break;
      case 4:
        sing_the_nightingale();
        break;
      case 5:
        seek_inner_wisdom();
        break;
      case 6:
        printf("May the tranquility you have found within guide you always.\n"
               "Farewell, and journey well.\n");
        return 0;
      default:
        printf("Invalid choice. Please choose a number from 1 to 6.\n");
    }
  }

  return 0;
}