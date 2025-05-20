#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  int offset = 0;
  int i = 0;

  // Malformed HTTP request with integer overflow
  char* request = "GET /?param1=127&param2=1&param3=127&param4=1&param5=127&param6=1&param7=127&param8=1&param9=1&param10=1&param11=1&param12=1&param13=1&param14=1&param15=1&param16=1&param17=1&param18=1&param19=1&param20=1&param21=1&param22=1&param23=1&param24=1&param25=1&param26=1&param27=1&param28=1&param29=1&param30=1&param31=1&param32=1&param33=1&param34=1&param35=1&param36=1&param37=1&param38=1&param39=1&param40=1&param41=1&param42=1&param43=1&param44=1&param45=1&param46=1&param47=1&param48=1&param49=1&param50=1";

  // Parse the request and exploit the overflow
  while (request[i] && offset < 1024) {
    if (request[i] == '&') {
      offset++;
    } else if (request[i] >= 'a' && request[i] <= 'z') {
      int paramValue = request[i] - 'a' + 1;
      paramValue *= 2;
      buffer[offset] = paramValue;
      offset++;
    }
    i++;
  }

  // Print the modified buffer
  printf("%s", buffer);

  return 0;
}
