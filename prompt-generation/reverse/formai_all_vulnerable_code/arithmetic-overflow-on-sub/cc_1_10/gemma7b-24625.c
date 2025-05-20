//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_STOCK_NUM 10
#define UPDATE_INTERVAL 2

typedef struct Stock {
  char name[20];
  double current_price;
  double previous_price;
  double change_percentage;
} Stock;

Stock stocks[MAX_STOCK_NUM] = {
  {"Apple Inc.", 140.0, 138.0, 1.6},
  {"Microsoft Corp.", 250.0, 248.0, 0.8},
  {"Amazon Inc.", 180.0, 178.0, 1.1},
  {"Tesla Inc.", 800.0, 790.0, 1.2},
  {"Google Inc.", 200.0, 198.0, 1.0},
  {"Facebook Inc.", 160.0, 158.0, 1.3},
  {"Intel Corp.", 50.0, 48.0, 2.1},
  {"IBM Corp.", 120.0, 118.0, 1.8},
  {"Oracle Corp.", 90.0, 88.0, 2.2},
  {"Cisco Systems Inc.", 60.0, 58.0, 2.0}
};

int main() {
  int i;
  time_t start_time, end_time;

  start_time = time(NULL);

  while (1) {
    for (i = 0; i < MAX_STOCK_NUM; i++) {
      stocks[i].previous_price = stocks[i].current_price;
      stocks[i].change_percentage = (stocks[i].current_price - stocks[i].previous_price) / stocks[i].previous_price * 100.0;

      printf("%s: %.2f, %.2f%% Change\n", stocks[i].name, stocks[i].current_price, stocks[i].change_percentage);
    }

    end_time = time(NULL);
    if (end_time - start_time >= UPDATE_INTERVAL) {
      start_time = end_time;
      printf("\n");
    }

    sleep(1);
  }

  return 0;
}