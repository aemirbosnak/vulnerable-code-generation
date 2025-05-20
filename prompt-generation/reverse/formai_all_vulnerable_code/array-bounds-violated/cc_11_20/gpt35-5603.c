//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

int main()
{
  char html[] = "<html>\n<head>\n\t<title>C HTML Beautifier</title>\n</head>\n<body>\n\t<h1>Hello, world!</h1>\n</body>\n</html>\n";
  int i, j, indent = 0, flag = 0;
  int html_length = strlen(html);
  char output[1024];

  // scanning the html string character by character
  for(i = 0; i < html_length; i++)
  {
    char current_char = html[i];
    if(current_char == '<')
    {
      flag = 1;
      if(html[i+1] == '/') // check for closing tag
        indent -= 2;
    }
    // new line for every opening tag
    if(flag && current_char != '>')
    {
      output[j++] = current_char;
      if(current_char == '"' || current_char == '\'') // checking for string attributes
      {
        char attribute_quote = current_char;
        while((i + 1) < html_length && html[++i] != attribute_quote)
        {
          output[j++] = html[i];
        }
      }
      continue;
    }
    flag = 0;

    if(current_char == '>')
    {
      output[j++] = current_char;
      output[j++] = '\n';

      // add indentation after opening tag
      if(html[i-1] == '/' || html[i-1] == '\n')
        continue;
      else if(html[i-1] != '/')
        indent += 2;
      for(int k = 0; k < indent; k++)
        output[j++] = ' ';
      if(html[i+1] != '<') // check for text inside the tag
      {
        int temp_i = i;
        while(++temp_i < html_length && html[temp_i] != '<')
          output[j++] = html[temp_i];
        i = temp_i - 1;
        continue;
      }
    }
    output[j++] = current_char;
  }
  printf("%s", output);
  return 0;
}