//FormAI DATASET v1.0 Category: Browser Plugin ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* plugin_name = "Mystery Browser Plugin";
char* plugin_version = "1.0";
char* plugin_description = "This browser plugin adds a layer of mystery to your browsing experience.";
char* plugin_author = "Your Name";

void setup_plugin() {
  printf("Setting up %s %s plugin...\n", plugin_name, plugin_version);
  printf("Adding a layer of mystery to your browsing experience...\n");
  printf("Plugin created by %s\n", plugin_author);
}

struct riddle {
  char* question;
  char* answer;
};

struct riddle riddles[] = {
  {"What is so delicate that saying its name breaks it?", "Silence"},
  {"What has a heart that doesn't beat?", "Artichoke"},
  {"What goes through cities and fields, but never moves?", "Road"},
  {"My life can be measured in hours. I serve by being devoured. Thin, I am quick; fat, I am slow. Wind is my foe. What am I?", "Candle"},
  {"What starts with an E, ends with an E, but only contains one letter?", "Envelope"},
  {"I am always hungry, I must always be fed. The finger I touch, will soon turn red. What am I?", "Fire"},
  {"Alive without breath, as cold as death; never thirsty, ever drinking, all in mail never clinking. What am I?", "Fish"},
  {"I am not alive, but I grow; I don't have lungs, but I need air; I don't have a mouth, but water kills me. What am I?", "Fire"},
  {"Tall I am young, short I am old. While with life I glow, wind is my foe. What am I?", "Candle"}
};

int num_riddles = sizeof(riddles) / sizeof(struct riddle);

void ask_riddle() {
  srand(time(NULL));
  int random_index = rand() % num_riddles;
  struct riddle random_riddle = riddles[random_index];
  printf("%s\n", random_riddle.question);
  char answer[50];
  scanf("%s", answer);
  if (strcmp(answer, random_riddle.answer) == 0) {
    printf("Correct!\n");
  } else {
    printf("Incorrect. The correct answer was \"%s\"\n", random_riddle.answer);
  }
}

int main() {
  setup_plugin();
  printf("%s\n", plugin_description);
  while (1) {
    ask_riddle();
  }
  return 0;
}