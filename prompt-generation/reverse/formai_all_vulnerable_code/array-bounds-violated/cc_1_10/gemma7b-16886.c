//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xml_parser(char *xml_data) {
  int i = 0;
  char tag[20];
  char data[1024];
  int state = 0; // 0 - neutral, 1 - tag start, 2 - tag end, 3 - data

  for (i = 0; xml_data[i] != '\0'; i++) {
    switch (state) {
      case 0:
        if (xml_data[i] == '<') {
          state = 1;
          tag[0] = xml_data[i];
        }
        break;
      case 1:
        if (xml_data[i] == '>') {
          state = 2;
          tag[1] = '\0';
          printf("Tag: %s\n", tag);
        } else {
          tag[i - 1] = xml_data[i];
        }
        break;
      case 2:
        if (xml_data[i] == '<') {
          state = 3;
          data[0] = xml_data[i];
        } else {
          data[i] = xml_data[i];
        }
        break;
      case 3:
        if (xml_data[i] == '>') {
          state = 0;
          data[i] = '\0';
          printf("Data: %s\n", data);
        } else {
          data[i] = xml_data[i];
        }
        break;
    }
  }
}

int main() {
  char xml_data[] = "<person><name>John Doe</name><age>30</age></person>";
  xml_parser(xml_data);
  return 0;
}